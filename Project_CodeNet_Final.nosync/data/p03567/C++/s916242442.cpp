#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi= vector<vi>;
using vs = vector<string>;
#define  rep(i,n) for(ll i = 0; i < (n); ++i)
#define  red(i,n) for(ll i = (n)-1; i >= 0; --i)
#define  all(a)   begin(a),end(a)
#define  pb(a)    push_back(a)
#define  mp(a,b)  make_pair(a,b)
#define  yn(a)    cout << ( (a)?"Yes\n":"No\n" )
inline ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
const ll INF = 1e9+7, LINF = 1e18;


int main()
{
    string s;
    cin>>s;
    yn(s.find("AC")!=string::npos);

    return 0;
}