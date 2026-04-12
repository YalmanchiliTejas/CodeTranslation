#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repk(i,m,n) for(ll i=m;i<n;i++)
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define F first
#define S second
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int INF=2*1e9;
int main()
{
    bool a=0,b=0;
    string s;
    cin>>s;
    rep(i,s.size())
    {
        if(s[i]=='A') a=1;
        if(s[i]=='B') b=1;
    }
    if(a&b) cout<<"Yes";
    else cout<<"No";
}
