#include <stdio.h>

/*
输入学生成绩
  scores 指向成绩数组的指针
  n
学生人数
 */
void inputScores(int* scores, int n);

/*
计算平均分
 scores 指向成绩数组的指针
 n
学生人数
 return 平均分
 */
double calculateAverage(int* scores, int n);

/*
查找最高分和最低分
 scores 指向成绩数组的指针
 n
学生人数
 max 指向存储最高分的变量的指针
 min 指向存储最低分的变量的指针
 */
void findMinMax(int* scores, int n, int *max, int *min);

/*
对成绩进行降序排序
 scores 指向成绩数组的指针
 n
学生人数
 */
void sortScores(int* scores, int n);

/*
统计各等级人数
 scores 指向成绩数组的指针
 n
学生人数
 counts 指向等级统计数组的指针
 counts[0]: 优秀人数(90-100)
 counts[1]: 良好人数(80-89)
 counts[2]: 中等人数(70-79)
 counts[3]: 及格人数(60-69)
 counts[4]: 不及格人数(0-59)
 */
void countGrades(int* scores, int n, int* counts);



int main() 
{
    int numStudents;

    printf("请输入学生人数: \n");
    scanf_s("%d", &numStudents);

    int scores[100] = { 0 };
    int gradeCounts[5] = { 0 };
    
    // 调用各功能函数 
    inputScores(scores, numStudents);
    double avg = calculateAverage(scores, numStudents);
    printf("平均分: %.2f\n", avg);

    int maxScore = 0;
    int minScore = 0;

    findMinMax(scores, numStudents, &maxScore, &minScore);
    printf("最高分: %d, 最低分: %d\n", maxScore, minScore);

    sortScores(scores, numStudents);
    printf("成绩降序排列: ");
    for (int i = 0; i < numStudents; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    countGrades(scores, numStudents, gradeCounts);
    
    printf("等级统计:\n");
    printf("优秀(90-100): %d人\n", gradeCounts[0]);
    printf("良好(80-89): %d人\n", gradeCounts[1]);
    printf("中等(70-79): %d人\n", gradeCounts[2]);
    printf("及格(60-69): %d人\n", gradeCounts[3]);
    printf("不及格(0-59): %d人\n", gradeCounts[4]);
    return 0;
}

/*
输入学生成绩
  scores 指向成绩数组的指针
  n
学生人数
 */
void inputScores(int* scores, int n)
{
   ChongHui: printf("请输入这%d个学生的成绩(0~100)：\n", n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &scores[i]);
    
    for (int d = 0; d < n; d++)
        if (scores[d] < 0 || scores[d]>100)
            goto ChongHui;
    return;
}

/*
计算平均分
 scores 指向成绩数组的指针
 n
学生人数
 return 平均分
 */
double calculateAverage(int* scores, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += scores[i];
    double ave;
    ave = sum / n;
    return ave;
}

/*
查找最高分和最低分
 scores 指向成绩数组的指针
 n
学生人数
 max 指向存储最高分的变量的指针
 min 指向存储最低分的变量的指针
 */
void findMinMax(int* scores, int n, int *max, int *min)
{
    *max = scores[n-1];
    *min = scores[0];

    for (int i = n - 1; i >= 0; i--)
        if (*max < scores[i])
            *max = scores[i];

    for (int j = 0; j<=n-1; j++)
        if (*min > scores[j])
            *min = scores[j];

    return;
}

/*
对成绩进行降序排序
 scores 指向成绩数组的指针
 n
学生人数
 */
void sortScores(int* scores, int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n-1-i;j++)
            if (scores[j] < scores[j - 1])
            {
                int t = scores[j];
                scores[j] = scores[j-1];
                scores[j - 1] = scores[j];
            }
    return;
}

/*
统计各等级人数
 scores 指向成绩数组的指针
 n
学生人数
 counts 指向等级统计数组的指针
 counts[0]: 优秀人数(90-100)
 counts[1]: 良好人数(80-89)
 counts[2]: 中等人数(70-79)
 counts[3]: 及格人数(60-69)
 counts[4]: 不及格人数(0-59)
 */
void countGrades(int* scores, int n, int* counts) 
{
    for (int i = 0; i < n; i++)
        if (scores[i] >= 90)
            counts[0]++;
        else if (scores[i] >= 80)
            counts[1]++;
        else if (scores[i] >= 70)
            counts[2]++;
        else if (scores[i] >= 60)
            counts[3]++;
        else 
            counts[4]++;

}