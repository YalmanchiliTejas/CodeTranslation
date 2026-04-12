#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;


const ll MOD = (ll)998244353;
struct mint {
    long long x;
    mint(long long _x=0):x((_x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint modpow(long long t) const {
        if (!t) return 1;
        mint a = modpow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return modpow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& a){
        os << a.x;
        return os;
    }
};
/* dp[i][j][k]: 配列をi個見て、和がjで、
右端も決まってない(0), 
右端は決まっているが左端は決まっていない(1), 
両方決まっている(2)
*/
mint dp[3010][3010][3];
int N, S;
void debug(){
    rep(k,3){
        cerr <<"["<<k << "]" << endl;
        rep(i,N+1){
            rep(j,S+1){
                cerr << dp[i][j][k] <<" ";
            }
            cerr << endl;
        }
        cerr << endl;
    }
    cerr << endl;
}
int main() {
    cin >> N >> S;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    dp[0][0][0] = 1;
    //debug();
    rep(i,N){
            rep(j,S+1){
            //from 0
            {
                //to 0  まだ始まってすらないよ！
                dp[i+1][j][0] += dp[i][j][0];
                //to 1  左側は決めるけど和をとらないよ
                dp[i+1][j][1] += dp[i][j][0];
                //      iから始めるぜ
                dp[i+1][min(S+1, j+A[i])][1] += dp[i][j][0];
                //to 2
                dp[i+1][j][2] += dp[i][j][0];
                //        iから始めた瞬間に終わるぜ
                dp[i+1][min(S+1, j+A[i])][2] += dp[i][j][0];
            }
            //from 1
            {
                //to 1  今までのやつを反映させるぜ
                dp[i+1][j][1] += dp[i][j][1];
                //      引き続き区間を伸ばすぜ    
                dp[i+1][min(S+1, j+A[i])][1] += dp[i][j][1];
                //to 2  右側を決めるけどこれ以上増やさないぜ
                dp[i+1][j][2] += dp[i][j][1];
                //      ここで使って終わるぜ
                dp[i+1][min(S+1, j+A[i])][2] += dp[i][j][1];
            }
            //from 2
            {
                //to 2 単純に反映させるぜ
                dp[i+1][j][2] += dp[i][j][2];
            }
        }
        //debug();
    }
    //debug();
    cout << dp[N][S][2] << endl;
}