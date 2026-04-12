#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,dp[5][10010];
char a,b,c;

int main()
{
	cin>>a;
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') puts("vowel");
	else puts("consonant");
}