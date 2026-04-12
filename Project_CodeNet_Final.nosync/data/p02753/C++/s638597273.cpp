// ConsoleApplication98.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
	int a=0,b=0;
	string ss;
	cin >> ss;
	for (int q = 0; q < 3; q++)
	{
		if (ss[q] == 'A')
		{
			a++;
		}
		else
		{
			b++;
		}
	}
	if (a == 0 || a == 3)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}


}