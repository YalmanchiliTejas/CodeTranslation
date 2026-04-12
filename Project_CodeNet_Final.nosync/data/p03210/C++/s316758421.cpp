/*
Look at the star
Look at the shine for U
*/
#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define sl(x) scanf("%lld",&x)
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
ll inv(ll b){if(b==1)return 1; return (mod-mod/b)*inv(mod%b)%mod;}
ll fpow(ll n,ll k){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%mod;n=n*n%mod;}return r;}

int main()
{
    ll n;
    while(cin >> n)
    {
        if(n == 3 || n== 5 || n==7)
            cout << "YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}