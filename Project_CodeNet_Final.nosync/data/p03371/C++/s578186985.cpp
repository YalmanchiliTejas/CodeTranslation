#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll f(ll a, ll b){
    string s=to_string(a),t=to_string(b);
    ll na=s.size(),nb=t.size();
    return max(na,nb);
}

int main(void)
{
    ll a,b,c,x,y,ans=0;
    cin>>a>>b>>c>>x>>y;
    ans += min(x,y)*min(a+b,2*c);
    if(x>=y){
        x-=y;
        ans += min(x*a,2*c*x);
    }else{
        y-=x;
        ans += min(y*b,2*c*y);
    }
    cout << ans << endl;
    return 0;
}