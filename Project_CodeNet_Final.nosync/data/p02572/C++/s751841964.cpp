#include <bits/stdc++.h>

using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("http://in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define ff first
#define ss second
#define N 2000001
#define M 1000000007
#define INF 1000000000000000

ll gcd(ll a,ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}



int main()
{
    ll n,ans=0;
    cin>>n;
    ll a[n];
    ll inv[2];
    inv[1] = 1;ll i;
for ( i=2; i<=2; ++i)
	inv[i] = (M - (M/i) * inv[M%i] % M) % M;
    ll sum1=0,sum2=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum1=sum1%M+a[i]%M;
        sum1=sum1%M;
        sum2=sum2+(a[i]%M*a[i]%M)%M;
        sum2=sum2%M;
    }
    sum1=(sum1*sum1)%M;
    cout<<((sum1-sum2+M)%M*inv[2])%M;
    
}