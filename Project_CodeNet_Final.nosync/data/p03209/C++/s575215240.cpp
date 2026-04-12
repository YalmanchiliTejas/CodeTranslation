// AtCoder Beginner Contest 115 - Problem D: Christmas (https://atcoder.jp/contests/abc115/tasks/abc115_d)
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define REPN(i, N) for (int (i) = 0; (i) < N; (i)++)
#define DEC(i, b, a) for (int (i) = (b); (i) >= (a); (i)--)
#define DECN(i, N) for (int (i) = N - 1; (i) >= 0; (i)--)

#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))
#define LOGM(msg) (cerr << (msg))
#define LOGV(vec, sep) { cerr << #vec << " ="; for (const auto& v : (vec)) cerr << " " << v; cerr << (sep); }
#define LOGA(arr, N, sep) { cerr << #arr << " ="; for (int i = 0; i < N; ++i) cerr << " " << (arr)[i]; cerr << (sep); }
#define LOGA2(arr, N, M, sep) { cerr << #arr << " =\n"; for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cerr << (arr)[i][j] << " "; cerr << endl; } cerr << (sep); }

ostream& operator<<(ostream& os, const ii& p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

const int MAXN { 60 };

ll size[MAXN], ps[MAXN];

ll patties(ll N, ll X)
{
    // Corner case
    if (X == size[N])
        return ps[N];

    // A bun
    if (X == 1)
        return 0;

    --X;

    // A N - 1 burger
    ll res = 0;

    if (X > size[N - 1])
    {
        res += ps[N - 1];
        X -= size[N - 1];
    } else
        return res + patties(N - 1, X);

    // A pattie
    ++res;

    if (X == 1)
        return res;
    
    --X; 

    // Another N - 1 burger
    if (X > size[N - 1])
    {
        res += ps[N - 1];
        X -= size[N - 1];
    } else
        return res + patties(N - 1, X);

    // Another bun
    --X;

    return res;

}

void precomp()
{
    // O tamanho e o número de patties no nível i é precomputado
    size[0] = 1;
    ps[0] = 1;

    for (int i = 1; i < MAXN; ++i)
    {
        size[i] = 1 + size[i - 1] + 1 + size[i - 1] + 1;
        ps[i] = 2*ps[i - 1] + 1;
    }
}

void solve(ll N, ll X)
{
    auto ans = patties(N, X);

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    precomp();

    ll N, X;
    cin >> N >> X;

    solve(N, X);

    return 0;
}
