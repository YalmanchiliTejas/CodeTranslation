#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << x << endl

const int MOD = 1000000007;

ll modpow(ll x, ll y){
    if(y == 0) return 1;
    ll xx = modpow(x, y/2);
    xx *= xx;
    xx %= MOD;
    return y&1 ? xx*x%MOD : xx;
}

ll fact[1001], inv_fact[1001];

ll comb(int a, int b){
    if(a < b) return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a-b] % MOD;
}

int h,w;

int main(){
    char g[100][100];
    while(cin >> h >> w){
        rep(i,h) cin >> g[i];
        bool ok = true;
        rep(i,h)rep(j,w){
            if(g[i][j] != '#') continue;
            if(i != 0 || j != 0){
                int cnt = 0;
                if(i != 0){
                    cnt += g[i-1][j] == '#';
                }
                if(j != 0){
                    cnt += g[i][j-1] == '#';
                }
                if(cnt != 1){
                    ok = false;
                }
            }
            if(i != h-1 || j != w-1){
                int cnt = 0;
                if(i != h-1){
                    cnt += g[i+1][j] == '#';
                }
                if(j != w-1){
                    cnt += g[i][j+1] == '#';
                }
                if(cnt != 1){
                    ok = false;
                }
            }
        }

        cout << (ok ? "Possible" : "Impossible") << endl;
    }
}
