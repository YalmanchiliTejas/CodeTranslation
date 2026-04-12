#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
int a,b,c;
int main()
{
	scanf("%d %d %d",&a,&b,&c);
	int d=a*100+b*10+c;
	if (d%4==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}