
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>


using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;


char inv(const char& a) {
    if (a == 'S') return 'W';
    return 'S';
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N;
    cin >> N;

    string s;
    cin >> s;

    string ans[4];
    ans[0] = "SS";
    ans[1] = "SW";
    ans[2] = "WS";
    ans[3] = "WW";

    REP(i, N) {
        REP(j, 4) {
            if (ans[j][i+1] == 'S') {
                if (s[i] == 'o') ans[j] += ans[j][i];
                else ans[j] += inv(ans[j][i]);
            } else {
                if (s[i] == 'o') ans[j] += inv(ans[j][i]);
                else ans[j] += ans[j][i];
            }
        }
    }

    bool flag = true;
    REP(i, 4) {
        if(ans[i][1] != ans[i][N+1] || ans[i][0] != ans[i][N]) continue;
        flag = false;
        cout << string(ans[i].begin() + 1, ans[i].end() - 1) << endl;
        break;
    }

    if (flag) {
       cout << -1 << endl;
    }
    
}
