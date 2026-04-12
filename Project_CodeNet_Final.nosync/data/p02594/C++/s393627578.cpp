#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define io std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
ll qpow(ll a,ll n)
{
    ll r=1%P;
    for (a%=P; n; a=a*a%P,n>>=1)
        if(n&1)
            r=r*a%P;
    return r;
}
int main()
{
 int x;
 cin>>x;
 if(x>=30)  cout<<"Yes"<<endl;
 else  cout<<"No"<<endl;
}

