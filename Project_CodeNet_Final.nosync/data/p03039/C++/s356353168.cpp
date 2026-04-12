#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, x, n) for(int i = x; i > n; i--)
long long MOD = 1e9+7;
long long INF = 1e15;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll inv[K-1];
    rep2(i, 1, K-1){
        inv[i] = 1;
        ll e[40];
        e[0] = i;
        rep2(j, 1, 40){
            e[j] = (e[j-1]*e[j-1]) % MOD;
        }
        ll k = MOD-2;
        int count = 0;
        while(k > 0){
            if(k % 2 == 1){
                inv[i] *= e[count];
                inv[i] %= MOD;
            }
            k /= 2;
            count++;
        }
    }
    ll c = 1;
    rep2(i, 1, K-1){
        c *= (N*M-1-i);
        c %= MOD;
        c *= inv[i];
        c %= MOD;
    }
    ll sumx = N*(N-1)*(N+1)*M*M/6;
    ll sumy = M*(M-1)*(M+1)*N*N/6;
    ll sum = (sumx + sumy) % MOD;
    cout << (c * sum) % MOD << endl; 
}