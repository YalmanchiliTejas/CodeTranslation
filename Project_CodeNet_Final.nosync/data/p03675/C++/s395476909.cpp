#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;i++)
int a[1000000];
int main()
{
    int r=500000-1,l=500000;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
    	int x;
    	cin>>x;
    	if (i%2) a[++r]=x;
    	else a[--l]=x;
    }
    
    if (n%2)
    {
    	for (int i=r;i>l;i--) cout<<a[i]<<" ";
    	cout<<a[l];
    }
    else
    {
    	for (int i=l;i<r;i++) cout<<a[i]<<" ";
    	cout<<a[r];
    }
}