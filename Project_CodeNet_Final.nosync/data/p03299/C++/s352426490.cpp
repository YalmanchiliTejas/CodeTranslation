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

template<int mod>
struct ModInt {
    long long x;
 
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    explicit operator int() const {return x;}
 
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
 
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
 
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
 
    ModInt inverse() const{
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }

    ModInt power(long long p) const{
        int a = x;
        if (p==0) return 1;
        if (p==1) return ModInt(a);
        if (p%2==1) return (ModInt(a)*ModInt(a)).power(p/2)*ModInt(a);
        else return (ModInt(a)*ModInt(a)).power(p/2);
    }

    ModInt power(const ModInt p) const{
        return ((ModInt)x).power(p.x);
    }

    friend ostream &operator<<(ostream &os, const ModInt<mod> &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt<mod> &a) {
        long long x;
        is >> x;
        a = ModInt<mod>(x);
        return (is);
    }
};

using modint = ModInt<mod>;



int n,h[110],v[110];
set<int> se={1};
map<int,int> inv_v;
modint dp[110][110];

void solve(){
    cin >> n;
    rep(i,n){
        cin >> h[i];
        se.insert(h[i]);
    }
    int it=0;
    int m=se.size();
    for(int s:se){
        inv_v[s]=it;
        v[it]=s;
        it++;
    }
    v[m]=mod;
    // cout << m << endl;
    // rep(i,m+1){
    //     cout << v[i] << " ";
    // }
    // cout << "" << endl;
    per(j,inv_v[h[0]]+1){
        if(j==inv_v[h[0]])dp[0][j]=2;
        else dp[0][j]=((modint)2).power(h[0]-v[j+1]+1)*(((modint)2).power(v[j+1]-v[j])-1);
    }
    rep(i,n-1){
        rep(j,m){
            if(v[j]>h[i]) continue;
            if(v[j+1]<=min(h[i],h[i+1])) dp[i+1][j]+=((modint)2).power(max(0,h[i+1]-h[i]))*dp[i][j];
            else if(v[j]>=h[i+1]) dp[i+1][inv_v[h[i+1]]]+=(modint)2*dp[i][j];
            else if(v[j]==h[i] && v[j]<h[i+1]){
                Rep(k,j,m){
                    if(v[k]<h[i+1]) dp[i+1][k]+=((modint)2).power(h[i+1]-v[k+1]+1)*(((modint)2).power(v[k+1]-v[k])-1)*dp[i][j];
                    else if(v[k]==h[i+1]) {
                        dp[i+1][k]+=(modint)2*dp[i][j];
                    }
                }
            }
        }
    }
    // rep(i,n){
    //     rep(j,m){
    //         cout << i << "  [" << v[j] << "," << v[j+1] << ") " << dp[i][j] << endl;
    //     }
    // }
    modint ans=0;
    rep(i,m){
        ans+=dp[n-1][i];
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}