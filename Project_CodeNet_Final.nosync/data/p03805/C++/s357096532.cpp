#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m; cin >> n >> m;
    vector<int> g[n];
    vector<int> v(n - 1);
    rep(i, m)
    {
        int a, b; cin >> a >> b;
        a--;b--;
        g[a].push_back(b), g[b].push_back(a);
    }
    rep(i, n - 1) v[i] = i + 1;

    int ans = 0;
    do
    {
        int now = 0;
        bool ok;
        rep(i, n - 1)
        {
            ok = false;
            for(auto it : g[now])
            {
                if (it == v[i])
                {
                    ok = true;
                    now = v[i];
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) ans++;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}