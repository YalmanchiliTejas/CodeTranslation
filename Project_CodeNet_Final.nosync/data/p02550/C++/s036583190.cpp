#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

ll n;int m,x;
int to[100010][65];
ll table[100010][65];

void solve(){
    cin >> n >> x >> m;
    rep(i,m){
        to[i][0]=(ll)i*(ll)i%m;
        table[i][0]=i;
    }
    rep(j,35){
        rep(i,m){
            to[i][j+1]=to[to[i][j]][j];
            table[i][j+1]=table[i][j]+table[to[i][j]][j];
            //cout << i << " " << j+1 << " " << table[i][j+1] << endl;
        }
    }
    ll ans=0;int pos=x;
    rep(j,35){
        if(n&(1ll << j)){
            //cout << table[pos][j] << endl;
            ans+=table[pos][j];
            pos=to[pos][j];
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}