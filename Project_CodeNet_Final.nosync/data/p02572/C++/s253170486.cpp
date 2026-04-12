#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e15
ll vec[200009];
ll cum[200009];
ll M;
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    M=(1e9)+7;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&vec[i]);
    }
    for(i=n;i>=1;i--)
    {
        cum[i]=(cum[i+1]+(vec[i]%M))%M;
    }
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        a=vec[i]%M;
        b=cum[i+1];
        a=(a*b)%M;
        ans=(ans+a)%M;
    }
    cout<<ans<<endl;
}
