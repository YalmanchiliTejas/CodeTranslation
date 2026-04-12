#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const vi d8x = {1, 0, -1, 0, 1, -1, -1, 1};
const vi d8y = {0, 1, 0, -1, 1, 1, -1, -1};
const vi d4x = {1, 0, -1, 0};
const vi d4y = {0, 1, 0, -1};

//---------------from here-----------------

int main(){
    ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    ll ans=INF;
    for(ll ab=0; ab<=max(x,y)*2; ab++){
        ll sum=0;
        sum+=ab*c;
        sum+= max((y-ab/2),0LL) *b;
        sum+= max((x-ab/2),0LL) *a;
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
}