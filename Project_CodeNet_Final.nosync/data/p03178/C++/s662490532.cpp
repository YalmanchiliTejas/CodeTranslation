#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll Mod = 1e9 + 7;
const ll N = 10100;

ll Rec(ll i=0,ll m=0,bool Equal=true);

string k;
ll n;
ll D;
ll s[N];

ll Dp[N][110][2];

int main()
{
    memset(Dp,-1,sizeof(Dp));

    cin>>k>>D;

    n = k.size();

    for(ll i=0;i<n;i++) s[i] = k[i] - '0';

    cout<<(Rec()-1+Mod)%Mod;
}

ll Rec(ll i,ll m,bool Equal)
{
    if(i==n)    return m==0;

    if(Dp[i][m][Equal]+1)   return Dp[i][m][Equal];

    ll Res = 0;

    for(ll j = 0 , L = Equal ? s[i] : 9 ; j<=L ; j++ )  Res += Rec(i+1,(m+j)%D,Equal&&s[i]==j);

    return Dp[i][m][Equal] = Res%Mod;
}