#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map>  
using namespace std;

struct point
{
	bool check;
	int number;
}p[100][100];
int n, i, m, ans, j;
int a[50];
int main()
{
	cin >> n;
	memset(p, 0, sizeof(p));
	for (i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		m = str.length();
		for (j = 0; j < m; j++)
		{
			p[i][str[j] - 'a'].check = true;
			p[i][str[j] - 'a'].number++;
		}
	}
	for (i = 0; i < 26; i++)
	{
		ans = 1000000;
		for (j = 1; j <= n; j++)
		{
			if (p[j][i].check == true)
			{
				ans = min(ans, p[j][i].number);
			}
			else
			{
				ans = 0;
				break;
			}
		}
		a[i] = ans;
	}
	for (i = 0; i < 26; i++)
	{
		while (a[i]--)
		{
			cout << char(i + 'a');
		}
	}
	cout << endl;
}