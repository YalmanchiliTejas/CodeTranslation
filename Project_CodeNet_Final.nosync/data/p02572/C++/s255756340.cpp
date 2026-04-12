#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi 3.14159265358979323846
#define mod 1000000007
int main()
{ 
    IOS;
    ll p;
    p=1;
    while(p--)
    {
        ll a,b,c,d,e,n,maxx=0,sum1=0;
        cin>>a;
        ll A[a],sum[a]={0};
        for(b=0;b<a;b++)
        {
            cin>>A[b];
            sum1=sum1+A[b];
            if(b!=0)
            sum[b]=sum[b-1]+A[b];
            else
            sum[b]=A[b];
        }
        for(b=0;b<a;b++)
        {
            maxx=maxx+((A[b]%mod)*((sum1-sum[b])%mod))%mod;
            maxx%=mod;
        }
        cout<<maxx<<endl;
    }
}