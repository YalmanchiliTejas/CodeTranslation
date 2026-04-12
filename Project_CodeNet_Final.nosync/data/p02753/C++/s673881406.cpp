#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll N, K, T, W, H, M, C;

const int MAX = 510000;
const int MOD = 1e9;

const double PI=3.14159265358979323846;

/*
long long fac[MAX], finv[MAX], inv[MAX];

vector<double> cx, cy, c;
 ll MM = 1e12;

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

std::vector<int> Eratosthenes(int n ){
    std::vector<bool> is_prime( n + 1 );
    for( int i = 0; i <= n; i++ ) is_prime[ i ] = true;
    std::vector<int> P;
    for( int i = 2; i <= n; i++ ){
        if( is_prime[ i ] ){
            for( int j = 2 * i; j <= n; j += i ){
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}*/

int length(vector<int> v, int u, int HW){
    if(v.size() == 0) return HW;
    if(v[0] > u) return v[0];
    if(v[v.size() - 1] < u) return HW - v[v.size()- 1] -1;
    else{
        int i = lower_bound(ALL(v), u)- v.begin();
        return v[i] - v[i-1] -1;
    }
}

int main(){
    string str;
    cin >> str;
    if(str[0] == str[1] and str[1] == str[2]) cout << "No";
    else cout << "Yes";
}
