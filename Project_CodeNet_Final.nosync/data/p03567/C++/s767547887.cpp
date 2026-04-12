#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
	char s[10];
	scanf("%s", s); int n = strlen(s);
	for (int i = 0; i < n-1; i ++)
		if (s[i] == 'A' && s[i+1] == 'C'){
			puts("Yes"); return 0;
		}
	puts("No"); return 0;
}