#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;

template <int mod>
struct ModInt{
    int x;
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p){
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p){
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p){
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p){
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
        while (b > 0){
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }

    ModInt pow(int e){
        long long a = 1, p = x;
        while (e > 0){
            if (e % 2 == 0){
                p = (p * p) % mod;
                e /= 2;
            }
            else{
                a = (a * p) % mod;
                e--;
            }
        }
        return ModInt(a);
    }

    friend ostream &operator<<(ostream &os, const ModInt<mod> &p){
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt<mod> &a){
        long long x;
        is >> x;
        a = ModInt<mod>(x);
        return (is);
    }
};

using modint = ModInt<mod>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int d;
    cin>>s>>d;
    int n=s.size();
    modint dp[n+5][2][105];
    //dp[i][j][k]:i桁目までみたとき、それが値以下(j=1で未満が確定)で、かつmodがいくつか
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<105;k++)dp[i][j][k]=0;
        }
    }
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int m=0;m<d;m++){
                int lim=j?9:s[i]-'0';
                for(int k=0;k<=lim;k++){
                    dp[i+1][j||k<lim][(m+k)%d]+=dp[i][j][m];
                }
            }
        }
    }
    modint res=dp[n][0][0]+dp[n][1][0]-1;
    cout<<res<<endl;
}