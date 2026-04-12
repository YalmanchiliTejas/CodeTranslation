#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for(int i = 0; i < (n); i++)
#define REPS(i, n)  for(int i = 1; i <= (n); i++)
#define RREP(i, n)  for(int i = (n)-1; i >= 0; i--)
#define RREPS(i, n) for(int i = (n); i > 0; i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define mt make_tuple
#define pb push_back

using ll  = long long;
using pi  = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.141592653589793;
const double EPS = 1e-9;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N; cin >> N;
    string s; cin >> s;

    int sheep[2] = {1, -1};
    REP(i, 2)
    {
        REP(j, 2)
        {
            vi v(N, 0);
            v[0] = sheep[i];
            v[N-1] = sheep[j];

            bool ok = true;

            REP(k, N)
            {
                int pre = (k-1+N) % N, suc = (k+1) % N;
                int next = v[pre];
                if((v[k] == 1 && s[k] == 'x') || (v[k] == -1 && s[k] == 'o')) next *= -1;
                if(v[suc] != 0 && v[suc] != next) ok = false;
                v[suc] = next;
            }

            if(ok)
            {
                REP(k, N)
                {
                    if(v[k] == 1) cout << 'S';
                    else cout << 'W';
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}