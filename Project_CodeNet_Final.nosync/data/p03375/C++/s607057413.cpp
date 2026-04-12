//https://arc096.contest.atcoder.jp/tasks/arc096_c
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define DEBUG(x) { cerr << #x << '=' << x << endl; }
#define Arr(a, l, r) { cerr << #a << " = {"; FOR(_, l, r) cerr << ' ' << a[_]; cerr << "}\n"; }
#define N 3030
#define pp pair<int, int>
#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define taskname ""
#define bit(S, i) (((S) >> (i)) & 1)
using namespace std;

// f[n][k] : Divide n people into k group and someone can belong to no group.

int n;
long long MOD, f[N][N], c[N][N];

long long Pow(long long a, long long k, long long MOD) {
    if (k == 0) return 1;
    long long t = Pow(a, k >> 1, MOD);
    t = t * t % MOD;
    if (k % 2) t = t * a % MOD;
    return t;
}
long long POW[N], PPOW[N];
void Init() {
    cin >> n >> MOD;
    f[0][0] = c[0][0] = 1;
    FOR(nn, 1, n) {
        c[nn][0] = f[nn][0] = 1;
        FOR(k, 1, nn) {
            f[nn][k] = (f[nn - 1][k - 1] + f[nn - 1][k] * (k + 1)) % MOD;  
            c[nn][k] = (c[nn - 1][k] + c[nn - 1][k - 1]) % MOD;
        }
    } 
    POW[0] = 1;
    PPOW[0] = Pow(2ll, 1, MOD);
    FOR(i, 1, n) {
        POW[i] = POW[i - 1] * 2 % (MOD - 1);
        PPOW[i] = Pow(2ll, POW[i], MOD);
    }
}


// Way(i) = Sum(Way2(i, j)), j = 1..i
long long calWay2(int i, int j) {
    //Divide i first elements into j ramen and add ramen of (n - i) another elements to j groups or outside.
    long long res = f[i][j];
    //DEBUG(i);DEBUG(j);DEBUG(f[i][j]);
    res = res * Pow(2ll, 1ll * (n - i) * j, MOD) % MOD; 
    //return res;
    // (2 ^ (n - 1) -> number of ramen of j topping) ^ j -> into j groups
    res = res * PPOW[n - i] % MOD;
    // 2 ^ (2 ^ (n - 1)) -> Choose ramen of (n - i) topping outside
    // 2 ^ (p - 1) mod p = 1 mod p
    return res;
}

// Number ways to topping 1..i used at most one, i + 1..n is arbitrary.    
long long calWay(int i) {
    long long res = 0;
    FOR(j, 0, i) res = (res + calWay2(i, j)) % MOD;
    return res;
}

// -> Inclusion - exclusicion
void Solve() {
    long long hs = -1;
    long long res = 0;
    FOR(i, 0, n) {
        hs *= -1;
        res = (res + MOD + hs * c[n][i] * calWay(i) % MOD) % MOD;
    }
    cout << res << '\n';
}
int main() {
    #ifdef NERO
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    double stime = clock();
    #else 
        //freopen(taskname".inp","r",stdin);
        //freopen(taskname".out","w",stdout);
    #endif //NERO
    IO;
    Init();
    Solve();
    #ifdef NERO
    double etime = clock();
    cerr << "Execution time: " << (etime - stime) / CLOCKS_PER_SEC * 1000 << " ms.\n";
    #endif // NERO
}