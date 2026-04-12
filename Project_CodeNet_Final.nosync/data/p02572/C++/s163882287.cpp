#include<bits/stdc++.h>
#define lg long long int
#define loop(i,s,e) for(lg i=s;i<=e;i++)
#define iloop(i,s,e) for(lg i=e;i>=s;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;

lg min(lg a,lg b)
{return a<b?a:b;}
lg max(lg a,lg b)
{return a>b?a:b;}
lg lcm(lg a ,lg b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
    lg n;
    cin>>n;
    vector<lg>a(n,0);
    vector<lg>b(n,0);

    for(lg i=0;i<n;i++)
        cin>>a[i];

    b[n-1]=a[n-1];
    for(lg i=n-2;i>=0;i--)
        b[i]=(a[i]+b[i+1])%mod;
    lg ans=0;
    for(lg i=0;i<n-1;i++)
        ans=(ans+((a[i]*b[i+1])%mod))%mod;
    cout<<ans%mod<<endl;
}
