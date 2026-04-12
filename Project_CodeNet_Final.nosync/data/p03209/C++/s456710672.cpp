#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

ll n,x;
vll bn(51), an(51);

ll dp(ll l, ll d){
    if(l==0)return (d>=1?1ll:0);
    if(d<=1)return 0;
    if(d>=(an[l]-1)/2+1){
        return bn[l-1]+dp(l-1, min(d-(an[l]-1)/2-1, an[l-1]))+1ll;
    }else{
        return dp(l-1, d-1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    debug("debug test\n");
    cin>>n>>x;
    ll sta = 1, stb = 1;

    rep(i, 51){
        bn[i] = stb;
        an[i] = sta;
        sta = 2*sta+3;
        stb = 2*stb+1;
    }
    cout << dp(n, x) << endl;
    return 0;
}
