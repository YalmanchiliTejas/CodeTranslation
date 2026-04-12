#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,k;
long long ans=0;
int main()
{
    int i,j;
    cin>>n>>k;
    
    long long r,c;
    long long n0;
    for(r=k+1;r<=n;r++)
    {
        n0=n/r*r;
        
        ans+=n/r*(r-k);
        
        c=n-n0;
        ans+=max(0ll,c-k+1);
        if(k==0)ans--;
    }
    
    cout<<ans<<endl;
    return 0;
}
