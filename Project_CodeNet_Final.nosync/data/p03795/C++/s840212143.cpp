#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long x,y,n,m;
int main()
{
	cin>>n;
	m=n*800;
	m-=200*(n/15);
	cout<<m<<endl;
	return 0;
}