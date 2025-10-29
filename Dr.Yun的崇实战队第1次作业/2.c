#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

void generateArray(int a[],int n);		// 生成随机数组
void printArray(int a[],int n);			// 打印数组

void bubbleSort(int a[],int n);			// 冒泡排序
void selectionSort(int a[],int n);		// 选择排序
void insertionSort(int a[],int n);		// 插入排序
void quickSort(int a[],int low,int high);			// 快速排序
void quickSortandPrint(int a[], int low, int high);

int main()
{
	int arr[100];
	int n;
	char ch;
	printf("请你决定生成多少个由100以内的整数组成的随机数列（上限为100）：");
	scanf_s("%d", &n);

	generateArray(arr,n);				// 生成随机数组
	printArray(arr,n);				// 打印数组

	printf("\n请你从以下4种排序方式中选择一种：\nA.冒泡排序\nB.选择排序\nC.插入排序\nD.快速排序\n\n");
	ch=_getch( );
	ch=toupper(ch);

	if (ch = 'A')
		bubbleSort(arr, n);						// 冒泡排序
	else if (ch = 'B')
		selectionSort(arr, n);					// 选择排序
	else if (ch = 'C')
		insertionSort(arr, n);					// 插入排序
	else if (ch = 'D')
		quickSortandPrint(arr, 0, n - 1);					// 快速排序
	else
		printf("输入错误");


	return 0;
}


//生成随机数组
void generateArray(int a[],int n)
{
	int i = 0;

	srand((unsigned)time(NULL));			//生成随机种子
	
	for (i=0; i <n; i++) 
	{							
		a[i] = rand() % 100;		//生成一个随机数（0到99），并赋值给a[i]
	}
	
	return;
}

//打印原始数组
void printArray(int a[],int n)
{
	int i = 0;

	printf("\n原始数组：");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return;
}

//冒泡排序
void bubbleSort(int a[],int n)					
{
	int i ,j,t;
	
	for (i = 0; i < n-1; i++)
	{
		for(j=0;j<n-1;j++)
		{
			if (a[j] > a[j+1])
			{
				t = 0;
				t = a[j];
				a[j]=a[j+1];
				a[j+1] = t;
			}
		}
	}
	
	printf("\n冒泡排序：");
	for (int d=0;d<n;d++)
		printf("%d ", a[d]);
	printf("\n");
	return ;
}	

//选择排序
void selectionSort(int a[],int n)				
{
	int i, j, k,t;

	for (i = 0; i < n-1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (a[k] > a[j])
				k = j;
		if (k != i)
		{
			t = 0;
			t = a[i];
			a[i] = a[k];
			a[k] = t;
		}
	}
	printf("\n选择排序：");
	for (int d = 0; d < n; d++)
		printf("%d ", a[d]);
	printf("\n");
	return ;
}		

//插入排序
void insertionSort(int a[],int n) 
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		k = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > k))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}

	printf("\n插入排序：");
	for (int d = 0; d < n; d++)
		printf("%d ", a[d]);
	printf("\n");
	return ;
	
}

//快速排序
void quickSort(int a[],int low,int high) 
{
	
	int i = low, j = high;
	int k = a[i];

	{
		while (i < j)
		{
			while (i < j && a[j] >= k)
				j--;
			a[i] = a[j];

			while (i < j && a[i] <= k)
				i++;
			a[j] = a[i];
		}
		a[i] = k;

		if ((i - 1) > low)
			quickSort(a, low, i - 1);


		if ((j + 1) < high)
			quickSort(a, i + 1, high);
	}
	
	return;
}
void quickSortandPrint(int a[], int low, int high)
{
	int n;
	n = high - low + 1;

	quickSort(a, low, high);

	printf("\n快速排序：");
	for (int d = 0; d < n; d++)
		printf("%d ", a[d]);
	printf("\n");

	return;
}


