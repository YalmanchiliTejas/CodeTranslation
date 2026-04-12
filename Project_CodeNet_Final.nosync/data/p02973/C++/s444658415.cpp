#pragma GCC optimize(3)
#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N],d1[N],n;
int main()
{
	cin>>n;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int len1=1;
	d1[1]=a[1];
	for(int i=2; i<=n; i++)
	{
	    if(d1[len1]>=a[i])d1[++len1]=a[i];
	    else *upper_bound(d1+1,d1+1+len1,a[i],greater<int>())=a[i];
    }
    printf("%d\n",len1);
	return 0;
}