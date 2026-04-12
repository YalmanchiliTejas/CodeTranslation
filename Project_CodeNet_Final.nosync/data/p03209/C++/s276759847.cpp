#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
typedef long long ll;
ll f[60];
ll p[60];
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    f[0]=1;
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
	f[i]=3+2*f[i-1];
	p[i]=1+2*p[i-1];
//	cout<<f[i]<<' '<<p[i]<<endl;
    }
    ll sum=0;
    if(k>f[n])k=f[n];
    while(n>=0)
    {
	if(k==0) break;
	if(n==0)
        {
	    sum++;
	    break;
        }
//	if(k==0) break;
	if(k==f[n])
	{
	    sum+=p[n];
	    break;
	}
	if(k==f[n-1]+2)
	{
	    sum+=p[n-1]+1;
	    break;
	}
	if(k>f[n-1]+2)
	{
	    sum+=p[n-1]+1;
	    k=k-2-f[n-1];
	}
	else if(k<f[n-1]+2) k=k-1;
	n--;
    }
    cout<<sum<<endl;
}