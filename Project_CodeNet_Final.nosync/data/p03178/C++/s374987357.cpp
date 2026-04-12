#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long
#define MAX_V

struct modint{
    using i64=int_fast64_t;
    i64 a;
    static constexpr i64 MOD=1000000007;
    modint(){a=0;}
    modint(i64 a_){
        a=a_%MOD;
        if(a<0) a+=MOD;
    }
    modint inv()const{
        i64 n=1,m=MOD-2,A=a;
        while(m){
            if(m&1)(n*=A)%=MOD;
            (A*=A)%=MOD;
            m>>=1;
        }
        modint y(n);
        return y;
    }
    bool operator==(const modint& x){
        return a==x.a;
    }
    bool operator!=(const modint& x){
        return a!=x.a;
    }
    modint& operator=(const modint& x){
        a=x.a;
        return *this;
    }
    modint operator+(const modint& x){
        modint y;
        y.a=a+x.a;
        if(y.a>MOD) y.a-=MOD;
        return y;
    }
    modint operator-(const modint& x){
        modint y;
        y.a=a-x.a;
        if(y.a<0) y.a+=MOD;
        return y;
    }
    modint operator*(const modint& x){
        modint y;
        y.a=(a*x.a)%MOD;
        return y;
    }
    modint operator/(const modint& x){
        modint y;
        y.a=(a*x.inv().a)%MOD;
        return y;
    }
    modint& operator+=(const modint& x){
        a+=x.a;
        if(a>=MOD) a-=MOD;
        return *this;
    }
    modint& operator-=(const modint& x){
        a-=x.a;
        if(a<0) a+=MOD;
        return *this;
    }
    modint& operator*=(const modint& x){
        (a*=x.a)%=MOD;
        return *this;
    }
    modint& operator/=(const modint& x){
        (a*=x.inv().a)%=MOD;
        return *this;
    }
};
istream& operator>>(istream &in,modint& x){
    int_fast64_t a_;
    in>>a_;
    modint y(a_);
    x=y;
    return in;
}
ostream& operator<<(ostream &out,const modint& x){
    out<<x.a;
    return out;
}
modint pwr(int_fast64_t a,int_fast64_t b){
    modint _;
    int_fast64_t n=1,A=a;
    while(b){
        if(b&1) (n*=A)%=modint::MOD;
        (A*=A)%=modint::MOD;
        b>>=1;
    }
    _.a=n;
    return _;
}

/* dp[i][j][k]: 上からi桁目まで(1-indexed)見たときNで割った余りがjになるもの && 
                kはN未満かそうでないか(ぴったり) の個数 */ 
modint dp[100001][100][2];


int main(){
    int D;
    string S;
    cin >> S >> D;

    int L = S.size();
    dp[0][0][0] = 1;

    REP(i, L) REP(j, D) REP(l, 10) {
        /* 未満から未満 */
        dp[i+1][(j+l) % D][1] += dp[i][j][1];

        /* ぴったりから未満 */
        if(l < S[i] - '0') {
            dp[i+1][(j+l) % D][1] += dp[i][j][0];
        }

        /* ぴったりからぴったり */
        if(l == S[i] - '0') {
            dp[i+1][(j+l) % D][0] += dp[i][j][0]; 
        }
    }

    cout << dp[L][0][1] + dp[L][0][0] - 1 << endl;
}