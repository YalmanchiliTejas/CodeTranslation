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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef pair<int, int>P;
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
typedef vector<vector<ll>> mat;
typedef vector<int> vec;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
const ll mod = 1000000007;
const ll INF = mod * mod;
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll qp(ll a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };



void solve() {
    ll a, b, c, d, n, k, x,l,r;
    string s, t;
    ll ans = 0;
    double dans = 0;
    string sans = "Yes";
    vector<ll> re;
    vector<ll> de;

    cin  >> n;
    ll _max = 0;

    rep(i,n){
        cin >> a;
        if(a >= _max){
            ans++;
            _max = a;
        }
    }

    
    std::cout << ans << endl; 

    // std::cout << sans << endl; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    solve();
    // stop
        return 0;
}