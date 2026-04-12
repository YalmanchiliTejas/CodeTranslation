#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

template<int MOD>
class ModInt{
public:
    ModInt():value(0){}
    ModInt(long long val):value((int)(val<0?MOD+val%MOD:val%MOD)){ }

    ModInt& operator+=(ModInt that){
        value = value+that.value;
        if(value>=MOD)value-=MOD;
        return *this;
    }
    ModInt& operator-=(ModInt that){
        value -= that.value;
        if(value<0)value+=MOD;
        return *this;
    }
    ModInt& operator*=(ModInt that){
        value = (int)((long long)value * that.value % MOD);
        return *this;
    }
    ModInt &operator/=(ModInt that){
        return *this *= that.inverse();
    }
    ModInt operator+(ModInt that) const{
        return ModInt(*this)+=that;
    }
    ModInt operator-(ModInt that) const{
        return ModInt(*this)-=that;
    }
    ModInt operator*(ModInt that) const{
        return ModInt(*this)*=that;
    }
    ModInt operator/(ModInt that) const {
        return ModInt(*this) /= that;
    }
    ModInt pow(long long k) const{
        if(value == 0)return 0;
        ModInt n = *this, res = 1;
        while(k){
            if(k & 1)res *= n;
            n *= n;
            k >>= 1;
        }
        return res;
    }
    ModInt inverse() const {
        long long a = value, b = MOD, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }
    int toi() const{ return value; }

private:
    int value;
};
typedef ModInt<1000000007> mint;
ostream& operator<<(ostream& os, const mint& x){
    os << x.toi();
    return os;
}

vector<vector<int>> combinations(int n, int mod){
    auto res = vector<vector<int>>(n + 1, vector<int>(n + 1));
    rep(i, n + 1) res[i][0] = 1;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= i; ++j)
        res[i][j] = (res[i - 1][j - 1] + res[i - 1][j]) % mod;
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto co = combinations(1100, 1000000007);

    int N, A, B, C, D;
    while(cin >> N >> A >> B >> C >> D) {
        vector<mint> dp(N + 1);
        dp[0] = 1;

        for(int g = A; g <= B; ++g) {
            for(int i = N - g; i >= 0; --i) if(dp[i].toi()){
                mint x = 1;
                for(int j = 1; i + j*g <= N && j <= D; ++j) {
                    // N-i-(j-1)*g 人から g人選ぶ
                    x *= co[N - i - (j - 1)*g][g];
                    // 同じ人数からなるグループの並びを無視
                    x /= j;
                    if(C <= j && j<=D) {
                        dp[i + j*g] += dp[i] * x;
                    }
                }
            }
        }

        cout << dp[N] << endl;
    }
}
