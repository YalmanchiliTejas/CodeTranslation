// AtCoder Beginner Contest 127 - Problem E: Cell Distance (https://atcoder.jp/contests/abc127/tasks/abc127_e)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 200010 };
const ll MOD { 1000000007 };

int xs[MAX], ys[MAX];

ll fast_exp(ll a, ll n)
{
    ll res = 1, base = a;

    while (n)
    {
        if (n & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        n >>= 1;
    }
            
    return res;
}

ll inv(ll x)
{
    return fast_exp(x, MOD - 2);
}

ll binom(ll N, ll M)
{
    ll n = 1, a = 1, b = 1;

    for (ll i = 1; i <= N; ++i)
        n = (n * i) % MOD;

    for (ll i = 1; i <= (N - M); ++i)
        a = (a * i) % MOD;

    for (ll i = 1; i <= M; ++i)
        b = (b * i) % MOD;

    ll res = (n * inv(a)) % MOD;
    res = (res * inv(b)) % MOD;

    return res;
}

ll solve(ll N, ll M, ll K)
{
    // As distâncias entre as coordenadas x e y são independentes
    memset(xs, 0, sizeof xs);
    memset(ys, 0, sizeof ys);

    // Para um par de pontos P e Q, há (N x M - 2, K - 2) escolhas possíveis para os demais
    // pontos
    ll options = binom(N*M - 2, K - 2), ans = 0;

    // Há (N - d) maneiras de escolher um ponto com coordenada x = xi tal que existe ao menos
    // um ponto com coordenada x = xj e que xi + xj = d
    // Como a coordenada y de ambos pontos é livre, então há (N - d) x M^2 escolhas possíveis
    // para pares de pontos com distância 
    for (int d = 1; d < N; ++d)
    {
        ll qtd = ((N - d) * M) % MOD;
        qtd = (qtd * M) % MOD;
        qtd = (qtd * options) % MOD;
        qtd = (d * qtd) % MOD;

        ans = (ans + qtd) % MOD;
    }

    // O mesmo vale para y, invertendo-se os valores de N e M 
    for (int d = 1; d < M; ++d)
    {
        ll qtd = ((M - d) * N) % MOD;
        qtd = (qtd * N) % MOD;
        qtd = (qtd * options) % MOD;
        qtd = (d * qtd) % MOD;

        ans = (ans + qtd) % MOD;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, M, K;
    cin >> N >> M >> K;

    auto ans = solve(N, M, K);

    cout << ans << '\n';

    return 0;
}
