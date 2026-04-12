// ARC 077C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int a[222222];
int main()
{
	int n,i,x;
	cin>>n;
	for(i=1;i<=(n/2)*2;i=i+1){
		cin>>x;
		if(i&1)
			a[(n+i+1)/2]=x;
		else
			a[(n-i+2)/2]=x;
	}
	if(n&1){
		cin>>x;
		cout<<x<<' ';
		reverse(a+1,a+n);
	}
	for(i=1;i<=(n/2)*2;i=i+1)
		cout<<a[i]<<' ';
	return 0;
}