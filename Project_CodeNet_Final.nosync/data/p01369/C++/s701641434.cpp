#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>

#define rep(i,x) for(int i=0;i<x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rep_to(a,i,x) for(int i=a;i<x;i++)

using namespace std;

int main()
{
	string str;
	char left[50]="qwertasdfgzxcvb";
	char right[50]="yuiophjklnm";

	while(cin >> str && str!="#")
	{
		int flag=0;
		int keep=0;
		int count=0;

		rep(i,str.length())
		{
			if(i==0)
			{
				rep(j,15)if(left[j]==str[0])flag=1;
				rep(j,11)if(right[j]==str[0])flag=0;
				i++;
			}

			keep=flag;

			rep(j,15)if(left[j]==str[i])flag=1;
			if(keep!=flag)count++;
			keep=flag;

			rep(j,11)if(right[j]==str[i])flag=0;
			if(keep!=flag)count++;
		}
		cout << count <<endl;		
	}
}