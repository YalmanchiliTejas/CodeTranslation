#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

struct Culc {

    vector<long long> factorial;
    long long p;
    vector<vector <LL> > comb;
    vector<LL> inv;

    //階乗
    Culc(long long N, long long p_) {
        long long ans = 1;
        p=p_;
        factorial.push_back(ans);
        for (long long i = 1; i <= N; i++) {
            ans = ans * i % p;
            factorial.push_back(ans);
        }
        REP(i,N+1)comb.push_back(vector<LL> (N+1,-1));
        REP(i,N+1)inv.push_back(-1);
    }

    long long extgcd(long long a, long long b, long long &x, long long &y) {
        long long g = a;
        if (b) {
            g = extgcd(b, a % b, y, x);
            y -= x * (a / b);
        } else {
            x = 1;
            y = 0;
        }
        return g;
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }

    long long inverse(long long a, long long p) {
        long long x, y;
        extgcd(a, p, x, y);
        return ((x % p) + p) % p;
    }

    LL factinv(LL k){
        if(inv[k]>0)return inv[k];
        return inv[k]=inverse(factorial[k],p);
    }

//nCk mod p
//
    long long combination(long long n, long long k) {
        if(comb[n][k]>0)return comb[n][k];
        return comb[n][k] = factorial[n] * (inverse(factorial[k] * factorial[n - k] % p, p)) % p;
    }

};

int main(){

    LL N,A,B,C,D;cin>>N>>A>>B>>C>>D;
    LL inf = 1e9+7;

    //dp[i][j]:i人をj人以下のグループで分けるときの組み合わせ
    //dp[i][j] = dp[i][j-1] + iCj * dp[i-j][j-1] + iCj*(i-j)Cj/2 * dp[i-2*j][j-1] + ...
    //=dp[i][j-1] + sigma(for k=C; k<=D&&kj<=i;k++) dp[i-kj][j-1]* (iCj*(i-j)Cj*...*(i-(k-1)j)Cj)/k!
    //k=0 or C<=k<=D
    LL dp[N+1][B+1];
    fill(dp[0],dp[N+1],0);
    REP(i,B+1)dp[0][i]=1;
    Culc culc(N+1,inf);

    REP(i,N+1){
        for(LL j=A;j<=B;j++){
            LL sigma =0;
            LL comb=1;
            for(LL k=1;k<=D&&k*j<=i;k++){
                comb *= culc.combination(i-j*(k-1),j);
                comb %=inf;
                if(k<C)continue;
                sigma += ((dp[i-k*j][j-1]*comb)%inf)*culc.factinv(k)%inf;
                sigma %=inf;
            }
            dp[i][j]=(dp[i][j-1]+sigma)%inf;
        }
    }

    cout<<dp[N][B]<<endl;


    return 0;
}