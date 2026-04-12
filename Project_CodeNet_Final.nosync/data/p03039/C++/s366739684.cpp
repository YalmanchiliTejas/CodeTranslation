#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=1;i<=(n);++i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define DUMP(x) cout<<#x<<"="<<(x)<<endl;
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;

const lint MOD = (lint)1e9 + 7;

void mod_add(lint &a, lint b){
    a = (a+b) % MOD;
}

lint mod_pow(lint n, lint x){
    lint res = 1;
    while(x){
        if(x & 1) res = res * n % MOD;
        x >>= 1, n = n * n % MOD;
    }
    return res;
}

class ECellDistance {
public:
    lint N, M, K, L;
    vector<lint> fact, fact_inv;
    vector<vector<lint>> dp;

    void input(std::istream& in){
        ios_base::sync_with_stdio(false);
        in>>N>>M>>K;
        L = N * M;
        fact = vector<lint>(L+1, 1);
        fact_inv = vector<lint>(L+1, 1);
        dp = vector<vector<lint>>(N, vector<lint>(M, 0));
    }

    void comb_pre(int n){
        RREP(i, n) fact[i] = fact[i-1] * i % MOD;
        fact_inv[n] = mod_pow(fact[n], MOD-2);
        for(int i=L;0<i;i--) fact_inv[i-1] = fact_inv[i] * i % MOD;
    }

    lint comb(int n, int r){
        if(n<r or n<0 or r<0) return 0;
        return fact[n] * fact_inv[r] % MOD * fact_inv[n-r] % MOD;
    }

	void solve(std::istream& in, std::ostream& out) {
        input(in);
        comb_pre(L);
        lint ans = 0;
        RREP(i, N-1){
            mod_add(ans, i*M*M%MOD*(N-i)%MOD*comb(L-2, K-2)%MOD);
        }
        RREP(i, M-1){
            mod_add(ans, i*N*N%MOD*(M-i)%MOD*comb(L-2, K-2)%MOD);
        }
        out<<ans<<'\n';
	}
};


int main() {
	ECellDistance solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
