/*
* @Author: 王文宇
* @Date:   2018-04-14 20:14:58
* @Last Modified by:   王文宇
* @Last Modified time: 2018-04-14 20:18:03
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
#define _for(i,a,b) for(int i=a;i<=b;i++)
int n,a[maxn],b[maxn];
int main(int argc, char const *argv[])
{
	int l,r;
	cin>>n;
	_for(i,1,n)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	_for(i,1,n)
	{
		if(b[i]<=a[n/2])cout<<a[n/2+1]<<endl;
		else cout<<a[n/2]<<endl;
	}
	return 0;
}