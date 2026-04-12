// ConsoleApplication7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int a, b;
	while (cin>>a>>b)
	{
		if (a != b)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
	}
}

