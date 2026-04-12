#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
char s[101000];
int f;
void F(int x1, int x2)   // 0ÀÇ 1 Ñò  ÀÇ¼Ù ÑòÕæ
{
	char S[101000];
	int len = strlen(s);
	S[0] = x1==1?'S':'W';
	S[1] = x2==1?'S':'W';
	for (int i = 2; i <= len+1; i++)
	{
		int k = i;
		if (k==len+1)
			k = 1;
		if (S[i-1]=='S')
		{
			if (s[k-1]=='o')
			{
				if (S[i-2]=='S')
					S[i]='S';
				else
					S[i]='W';
			}
			if (s[k-1]=='x')
			{
				if (S[i-2]=='S')
					S[i]='W';
				else
					S[i]='S';
			}
		}
		if (S[k-1]=='W')
		{
			if (s[k-1]=='o')
			{
				if (S[i-2]=='S')
					S[i] = 'W';
				else
					S[i] = 'S';
			}
			if (s[k-1]=='x')
			{
				if (S[i-2]=='S')
					S[i] = 'S';
				else
					S[i] = 'W';
			}
		}
	}
	if (S[len]==S[0]&&S[len+1]==S[1])
	{
		for (int i = 0; i < len; i++)
			printf("%c", S[i]);
		printf("\n");
		f=1;
	}
	return;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	scanf(" %s", s);
	f=0;
	for (int i = 1; i >= 0; i--)
	{
		for (int j = 1; j >= 0; j--)
		{
			F(i,j);
			if (f==1)
				break;
		}
		if (f==1)
			break;
	}
	if (f==0)
		printf("-1\n");
	return 0;
}