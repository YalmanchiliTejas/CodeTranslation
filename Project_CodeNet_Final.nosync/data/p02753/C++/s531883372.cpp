#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	char s[3];
	for(int i=0;i<3;i++)
		scanf("%c",&s[i]);
	bool flag=false;
	for(int i=0;i<3;i++)
		if(i>0&&s[i]!=s[i-1])
			flag=true;
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
}


