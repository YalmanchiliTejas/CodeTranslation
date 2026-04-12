#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<int, ld> Pid;
typedef pair<int, string> Pis;
#define rep(i,n) for(int i=0; i<n; i++)
#define repm(i,s,n) for(int i=s; i<n; i++)
#define all(a) (a).begin(), (a).end()

const int INF = 1 << 30;
const ll INF_L = 1LL << 60;
const int MOD = 1e9+7; // 998244353;

void coi(ll i) {cout << i << endl;}
void cois(ll i) {cout << i << " ";}
void cod(ld d) {cout << fixed << setprecision(16); cout << d << endl;}
void cods(ld d) {cout << fixed << setprecision(16); cout << d << " ";}
void coc(char c) {cout << c << endl;}
void cocs(char c) {cout << c << " ";}
void cos(string s) {cout << s << endl;}
void coss(string s) {cout << s << " ";}
void coynl(bool b) {cos(b ? "Yes" : "No");}
void coYNU(bool b) {cos(b ? "YES" : "NO");}

// ----------------------------------------------------------------
// String Functions
// ----------------------------------------------------------------
int ctoi(char c){
    if(isdigit(c)) return c - '0';
    else if(islower(c)) return c - 'a';
    else if(isupper(c)) return c - 'A';
    else return -1;
}
char itocd(int i){char c = i+'0'; if(isdigit(c)) return c; else return 0x00;}
char itocl(int i){char c = i+'a'; if(islower(c)) return c; else return 0x00;}
char itocu(int i){char c = i+'A'; if(isupper(c)) return c; else return 0x00;}
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Dynamical Programming
// ----------------------------------------------------------------
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Graph Theory
// ----------------------------------------------------------------
struct edge {ll to, cost;};
struct GraphList {
    ll V;
    vector<vector<edge>> graph;
    vector<ll> dist;
    
    GraphList(ll N){
        init(N);
    }
    void init(ll N){
        V = N;
        graph.resize(V);
        dist.resize(V);
        for (int i = 0; i < V; i++) {dist[i] = INF_L;}
    }
    void add_edge(ll from, ll to, ll cost){
        edge e;
        e.to = to;
        e.cost = cost;
        graph[from].push_back(e);
    }
    
    void dijkstra(ll s){
        for (int i = 0; i < V; i++) {dist[i] = INF_L;}
        dist[s] = 0;
        
        priority_queue<Pll, vector<Pll>, greater<Pll>> que;
        que.push(Pll(0, s));
        while (!que.empty()) {
            Pll p = que.top(); que.pop();
            ll v = p.second;
            if (dist[v] < p.first) continue;
            for (auto e : graph[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push(Pll(dist[e.to], e.to));
                }
            }
        }
    }
    void bellman_ford(ll s){
        for (int i = 0; i < V; i++) {dist[i] = INF_L;}
        dist[s] = 0;
        
        /* Under construction */
        
    }
};
struct GraphMatrix {
    ll vertex;
    vector<vector<edge>> graph;
    vector<ll> dist;
    
    GraphMatrix(ll N){
        init(N);
    }
    void init(ll N){
        vertex = N;
        graph.resize(vertex);
        dist.resize(vertex);
        for (int i = 0; i < vertex; i++) {dist[i] = INF;}
    }
    void add_edge(ll s, ll t, ll cost){
        edge e;
        e.to = t;
        e.cost = cost;
        graph[s].push_back(e);
    }
    
    void warshall_floyd (ll s){
        for (int i = 0; i < vertex; i++) {dist[i] = INF;}
        dist[s] = 0;
        
        /* Under construction */
    }
};

// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Mathematical Functions
// ----------------------------------------------------------------
ll gcd(ll A, ll B) {if(A%B==0){return(B);} else{return(gcd(B, A%B));}}
ll lcm(ll A, ll B) {return A * B / gcd(A, B);}

ll getDigit(ll N) {return (ll)(to_string(N).length());}
ll getDigitForBase(ll N, ll B) {if(B<2){return -1;} else if(B==10){return getDigit(N);} else{ll r=0; while(N!=0){N/=B;r++;} return r;}}
ll getDigitSum(ll N) {ll r=0; string Ns=to_string(N); for(int i=0; i<getDigit(N); i++){r+=ctoi(Ns[i]);} return r;}
ll getDivTimes(ll N, ll D) {ll r=0; while(N%D == 0) {N/=D; r++;} return r;}

ll powMod(ll B, ll P) {
    if(P == 0) return 1;
    if(P%2 == 0){ll t = powMod(B, P/2); return t*t % MOD;}
    return B * powMod(B, P-1) % MOD;
}
ll invMod(ll N) {return powMod(N, MOD-2);}

/* ----------------------------------
 Factorial, Permutation, Combination
 ---------------------------------- */
const ll FPC_INIT_SIZE_MAX = 1e6+9;

struct FPCMod {
    ll size;
    vector<ll> inv, fac, finv;
    
    FPCMod(ll N){
        init(N);
    }
    void init(ll N){
        size = (N > 1 && N < FPC_INIT_SIZE_MAX) ? N : FPC_INIT_SIZE_MAX;
        inv.resize(size);
        fac.resize(size);
        finv.resize(size);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < size; i++){
            fac[i] = fac[i-1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i-1] * inv[i] % MOD;
        }
    }
    
    ll inverseMod(ll N){return inv[N]%MOD;}
    ll factrialMod(ll N){return fac[N] % MOD;}
    ll factrialInverseMod(ll N){return finv[N] % MOD;}
    ll permutationMod(ll N, ll K){
        if (N < 0 || K < 0 || N < K) return 0;
        else return factrialMod(N) * factrialInverseMod(N-K) % MOD;
    }
    ll combinationMod(ll N, ll K){
        if (N < 0 || K < 0 || N < K) return 0;
        else if (N < size){ return factrialMod(N) * (factrialInverseMod(K) * factrialInverseMod(N-K) % MOD) % MOD;}
        else {
            ll ans = 1; ll Ks = K < N-K ? K : N-K;
            for (ll i = N; i > N-Ks; i--) {ans *= i; ans %= MOD;}
            return ans * factrialInverseMod(Ks) % MOD;
        }
    }
};

/* ----------------------------------
 Sieve Theory
 ---------------------------------- */
const ll SIEVE_INIT_SIZE_MAX = 1e9+9;
struct SieveEratosthenes {
    
    ll N_max;
    ll size, size_sqrt;
    vector<bool> sieve; bool sieve_fg;
    vector<ll> sievingp; bool sievingp_fg;
    vector<ll> primes; bool primes_fg;
    
    vector<int> skipPrimes = {2, 3, 5};
    vector<int> standReminders = {1, 7, 11, 13, 17, 19, 23, 29};
    vector<int> invidxStandReminders = {
        -1, 0, -1, -1, -1, -1, -1, 1, -1, -1,
        -1, 2, -1, 3, -1, -1, -1, 4, -1, 5,
        -1, -1, -1, 6, -1, -1, -1, -1, -1, 7
    };
    const int SP_prod = 2 * 3 * 5;
    int SR_size = 8;

    SieveEratosthenes(ll N, int c) {
        switch (c) {
            case 1 : sieve_fg = true; sievingp_fg = true; break;
            default: sieve_fg = true; sievingp_fg = false; break;
        }
        init(N);
    }
    void init(ll N) {
        N_max = (N > 1 && N < SIEVE_INIT_SIZE_MAX) ? N : SIEVE_INIT_SIZE_MAX;
        size = (N_max/SP_prod + 1) * SR_size;
        size_sqrt = ((ll)sqrt(N_max)/SP_prod + 1) * SR_size;
        sieve = vector<bool>(size, true);
        sievingp = vector<ll>(size, 0);
        primes.clear();
        
        sieveInit();
    }
    void sieveInit() {
        for (int i = 1; i < size_sqrt; i++) {
            if(!sieve[i]) continue;

            int num_i = idxtonum(i); coi(num_i);
            for (int j = num_i*num_i; j < N_max; j += num_i) {
                int idx_j = numtoidx(j);
                if(idx_j > 0) {
                    sieve[idx_j] = false;
                    sievingp[idx_j] = num_i;
                }
            }
        }
    }

    bool isPrime(int N) {
        if (!sieve_fg) return false;
        if (N < 2 || N >= N_max) return false;
        for (auto p : skipPrimes) {
            if(N == p) return true;
            if(N%p == 0) return false;
        }
        return sieve[numtoidx(N)];
    }
    ll getSievingPrime(int N) {
        if (!sievingp_fg) return -1;
        if (N < 2 || N >= N_max) return -1;
        for (auto p : skipPrimes) {
            if(N%p == 0) return p;
        }
        if (isPrime(N)) return N;
        return sievingp[numtoidx(N)];
    }
    
    int idxtonum(int idx) {
        return (idx/SR_size) * SP_prod + standReminders[idx%SR_size];
    }
    int numtoidx(int num) {
        int iiSR = invidxStandReminders[num%SP_prod];
        return iiSR < 0 ? -1 : (num/SP_prod) * SR_size + iiSR;
    }
};
struct SieveAtkinBernstein {
    ll N_max;
    ll size, size_sqrt;
    vector<bool> sieve;
    
    SieveAtkinBernstein(ll N) {
        init(N);
    }
    void init(ll N) {
        N_max = (N > 1 && N < SIEVE_INIT_SIZE_MAX) ? N : SIEVE_INIT_SIZE_MAX;
        size = N_max;
        size_sqrt = (ll)sqrt(size+0.1);
        sieve.resize(size);
        sieveInit(N);
    }
    void sieveInit(ll N) {
        sieve[2] = sieve[3] = true;
        
        int n = 0;
        for (int z = 1; z <= 5; z += 4) {
          for (int y = z; y <= size_sqrt; y += 6) {
            for (int x = 1; x <= size_sqrt && (n = 4*x*x+y*y) < size; x++) sieve[n] = !sieve[n];
            for (int x = y+1; x <= size_sqrt && (n = 3*x*x-y*y) < size; x += 2) sieve[n] = !sieve[n];
          }
        }
        for (int z = 2; z <= 4; z += 2) {
          for (int y = z; y <= size_sqrt; y += 6) {
            for (int x = 1; x <= size_sqrt && (n = 3*x*x+y*y) < size; x += 2) sieve[n] = !sieve[n];
            for (int x = y+1; x <= size_sqrt && (n = 3*x*x-y*y) < size; x += 2) sieve[n] = !sieve[n];
          }
        }
        for (int z = 1; z <= 2; z++) {
            for (int y = 3; y <= size_sqrt; y += 6) {
                for (int x = z; x <= size_sqrt && (n = 4*x*x+y*y) < size; x += 3) sieve[n] = !sieve[n];
            }
        }
        for (int k = 5; k <= size_sqrt; k++)
          if (sieve[k])
            for (int n = k*k; n < size; n += k*k) sieve[n] = false;
    }
    
    bool isPrime(ll N) {
        if (N < 0 || N >= N_max) return false;
        return sieve[N];
    }
};

/* ----------------------------------
 Prime Factorization
---------------------------------- */
map<ll, map<ll, ll>> primeFactorMap;
map<ll, set<ll>> primeFactorSet;
void primeFactorizeInit(){primeFactorMap.clear(); primeFactorSet.clear();}
void primeFactorize(ll N){
    if (N < 0 || N > INF_L) return;
    
    ll Nc = N, Nsq = sqrt(N+0.1);
    for (int k = 2; k <= Nsq; k++) {
        ll dt = 0; while(Nc%k == 0) {dt++; Nc /= k;}
        if(dt > 0) primeFactorMap[N][k] = dt;
        if(N%k == 0) {primeFactorSet[N].insert(k); primeFactorSet[N].insert(N/k);}
    }
    if (Nc != 1) primeFactorMap[N][Nc] = 1;
    primeFactorSet[N].insert(1);
    primeFactorSet[N].insert(N);
}
// ----------------------------------------------------------------



//* ****************  GLOBAL VARIABLES  **************** *//

//* **************************************************** *//

void input() {

}


void solve() {
    
    char c; cin >> c;
    cos((c=='a'||c=='e'||c=='i'||c=='o'||c=='u')? "vowel" :"consonant");
}

int main() {
    
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
