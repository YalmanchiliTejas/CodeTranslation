#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define endl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N = 1e5 + 10, inf = 1e18 + 10, mod = 1e9 + 7;
ll d[N][110][2];
int D;
string s;
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("prices.in", "r", stdin);
    //freopen("prices.out", "w", stdout);
    cin >> s >> D;
    for(int i = 0; i < s[0] - '0'; i++)
    {
        d[0][i % D][0]++;
    }
    d[0][(s[0] - '0') % D][1]++;
    for(int i = 1; i <= s.size() - 1; i++)
    {
        for(int j = 0; j < D; j++)
        {
            for(int k = 0; k < s[i] - '0'; k++)
            {
                (d[i][(j + k) % D][0] += d[i - 1][j][1]) %= mod;
            }
            d[i][(j + s[i] - '0') % D][1] = d[i - 1][j][1];
            d[i][(j + s[i] - '0') % D][1] %= mod;
            for(int k = 0; k < 10; k++)
            {
                d[i][(j + k) % D][0] += d[i - 1][j][0];
                d[i][(j + k) % D][0] %= mod;
            }
        }
    }
    cout << (d[s.size() - 1][0][1] + d[s.size() - 1][0][0] - 1 + mod) % mod;
}
