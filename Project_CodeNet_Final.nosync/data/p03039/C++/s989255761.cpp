#include <bits/stdc++.h>
#define debug(x) cerr << "\n" \
                      << #x << " = " << x << ".\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define print(xx) cout << (xx) << endl
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
const int INF = ((1LL << 30) + (1LL << 29));
const ll MOD = 1000000007;

/* 

*/
const int MAX = 200001;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// comb
// 二項係数計算
long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//================== INPUT ========================
int N, M, K;
//=================================================
void input()
{
    cin >> N >> M >> K;
}

//=================================================
void solve()
{
    COMinit();

    int xsum = 0;
    int ysum = 0;
    rep(i,M){
        xsum += i * (M-i) * N * N;
    }
    xsum %= MOD;
    xsum *= COM(N*M-2, K-2);
    rep(i,N){
        ysum += i * (N-i) * M * M;
    }
    ysum %= MOD;
    ysum *= COM(N*M-2, K-2);

    cout<<(xsum+ysum)%MOD<<endl;
}

//=================================================
signed main()
{
    input();
    solve();
    return 0;
}