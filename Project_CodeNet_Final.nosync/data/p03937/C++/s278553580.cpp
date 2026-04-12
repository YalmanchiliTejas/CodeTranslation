#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi= vector<vi>;
using vs = vector<string>;
using pl = pair<ll,ll>;
#define  rep(i,n) for(ll i = 0; i < (n); ++i)
#define  red(i,n) for(ll i = (n)-1; i >= 0; --i)
#define  all(a)   begin(a),end(a)
#define  pb(a)    push_back(a)
#define  mp(a,b)  make_pair(a,b)
#define  yn(a)    cout << ( (a)?"Possible\n":"Impossible\n" )
inline ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll INF = 1e9+9, LINF = 1e18;


int main(int argc,char* argv[])
{
    int h,w,ans=0;
    char q;
    cin>>h>>w;
    rep(i,h*w) {
        cin>>q;
        ans+=q=='#';
    }
    yn(ans==h+w-1);
    return 0;
}
