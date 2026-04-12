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

llint cnt = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

llint n, x;
llint len[51];
llint p[51];

llint dfs(int m, llint x);

int main()
{
        ci >> n >> x;

        len[0] = p[0] = 1;
        for(int i = 1; i <= n; i++) {
                p[i] = 1 + p[i - 1] * 2;
                len[i] = 3 + len[i - 1] * 2;
        }


        co << dfs(n, x) << en;

        return 0;
}

llint dfs(int m, llint x)
{
        if(m == 0) return 1;

        llint rec = 0;
        llint mid = len[m] / 2 + 1;

        if(1 < x && x < mid) {
                rec += dfs(m - 1, x - 1);
        } else if(x == mid) {
                rec += 1 + p[m - 1];
        } else if(mid < x){
                rec += 1 + p[m - 1] + dfs(m - 1, x - mid);
        }

        return rec;
}