#include<bits/stdc++.h>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<llint, llint> pll;
typedef vector<int> vi;
typedef vector<llint> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define ci cin
#define co cout
#define en endl
#define ln cout<< '\n'
#define rep(i, n) for(int i = 0; i < n; i++)
#define outl(x) cout<< (x) << '\n'
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

template<typename Tn> Tn gcd(Tn a, Tn b)
{
  return (b ? gcd(b, a % b) : a);
}

template<typename Tn> Tn lcm(Tn a, Tn b)
{
  return a / gcd(a, b) * b;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vi v[10];

int dfs(int idx, int bit, int cnt);

int main()
{
        ci >> n >> m;

        for(int i = 0; i < m; i++) {
                int a, b;
                ci >> a >> b;
                v[a].pb(b);
                v[b].pb(a);
        }

        co << dfs(1, 1, 1) << en;

        return 0;
}

int dfs(int idx, int bit, int cnt)
{
        if(cnt == n) return 1;
        int rec = 0;

        for(int i = 0; i < v[idx].size(); i++) {
                int next = v[idx][i];
                if((1 << (next - 1)) & bit) continue;

                rec += dfs(next, bit | (1 << (next - 1)), cnt + 1);
        }

        return rec;
}