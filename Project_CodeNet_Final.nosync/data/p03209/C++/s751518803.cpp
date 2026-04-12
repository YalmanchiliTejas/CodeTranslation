#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

vector<ll> aa, pp;

ll f(ll n, ll x){
    if(n==0) return 1; //iru?
    if(x==1) return 0;
    if(2<=x && x<=aa[n-1]+1) return f(n-1, x-1);
    if(x == aa[n-1]+2) return pp[n-1]+1;
    if(aa[n-1]+3 <= x && x <= 2*aa[n-1]+2) return f(n-1, x-aa[n-1]-2)+1+pp[n-1];
    if(x >= 2*aa[n-1]+3) return pp[n-1]*2+1;
}

void init(ll n) {
    for(int i=1;i<=n;i++){
        aa[i] = aa[i-1]*2 + 3;
        pp[i] = pp[i-1]*2 + 1;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x; cin>>n>>x;
    aa.resize(n+1); pp.resize(n+1);
    aa[0] = 1; pp[0] = 1;
    init(n);
    ll ans = f(n, x); 
    cout << ans << endl;
}

