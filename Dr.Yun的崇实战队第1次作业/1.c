#include <stdio.h>

double fibonacci_nth(int n);    //声明自定义函数，用于返回斐波拉契数列第n项的值
void fibonacci_sequence(int n);
double fibonacci_sum(int n);	 //声明自定义函数，用于返回斐波拉契数列前n项的和

int main()								//主函数
{
	int n;
	double Fibonacci_n, Fibonacci_sum;

	while (1) 
	{
		printf("请输入一个不大于90的正整数，以得出斐波那契数列的第n项，前n项和\n");
		scanf_s("%d", &n);
		if (n >= 0 && n <= 90)	break;
		printf("输入错误，请再次输入\n");
	}

	Fibonacci_n = fibonacci_nth(n);
	printf("斐波那契数列的第n项为%.0lf\n", Fibonacci_n);
	
	fibonacci_sequence(n);
	
	Fibonacci_sum = fibonacci_sum(n);
	printf("斐波那契数列的前n项和为%.0lf\n", Fibonacci_sum);

	return 0;
}

double fibonacci_nth(int n)			//定义函数斐波拉契数列
{
	int i = 0;
	double fibonacci_n = 0;

	double fibonacci[99];
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	while (i<=n-2)
    {
		fibonacci[i + 2]=fibonacci[i + 1]+fibonacci[i];
		i++;
	}
	fibonacci_n = fibonacci[n];
	return fibonacci_n;
}

double fibonacci_sum(int n)	//定义计算斐波那契数列前n项和的函数
{
	int i = 0;
	double Fibonacci_sumup = 0;

	while (i<=n)
	{
		Fibonacci_sumup += fibonacci_nth(i);
		i++;
	}
	
	return Fibonacci_sumup;
}

void fibonacci_sequence(int n)		//定义，输出斐波那契数列的前n项
{
	int i = 0;
	
	while (i <= n) 
	{	
		printf("F(%d)=%.0lf\n", i, fibonacci_nth(i));
		i++;
	}

	return;
}