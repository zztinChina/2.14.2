#include<stdio.h>
int cheng(int x, int y)
{
	return x * y;
}
int chu(int x, int y)
{
	return x / y;
}
int jia(int x, int y)
{
	return x + y;
}
int jian(int x, int y)
{
	return x - y;
}
void menu()
{
	printf("*************1.乘   2.除*************\n");
	printf("*************3.加   4.减*************\n");
	printf("**********      0.退出    *********\n");


}
void all(int(*pf)(int ,int ))
{
	printf("请输入两个数字\n");
	int x = 0;
	int y = 0;
	scanf_s("%d%d", &x, &y);
	int hehe = (*pf)(x, y);
	printf("%d\n", hehe);
}
int main()
{
	int n = 0;
	do
	{  
		menu();
		scanf_s("%d", &n);

		switch (n)
		{
		case 1:
			all(cheng);
			break;
		case 2:
			all(chu);
				break;
		case 3:
			all(jia);
			break;
		case 4:
			all(jian);
			break;
		default:
			break;
}
	} while (n);
	return 0;
}