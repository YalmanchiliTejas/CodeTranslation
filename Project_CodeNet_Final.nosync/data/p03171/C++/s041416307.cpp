#include <bits/stdc++.h>
using namespace std;
#define pr(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int dp[3001][3001][2];

void solve() {
        int n; cin >> n;
        vector<int> v(n);

        for (auto& i: v) cin >> i;

        memset(dp, -1, sizeof(dp));

        function<int(int, int, bool)> calc= [&](int i, int j, bool pl)->int{
                if (i> j) {
                        return 0;
                }

                int &ret1= dp[i][j][pl];
                if (ret1!= -1) return ret1;

                if (pl) {
                        ret1= -1e18;
                        ret1= max(ret1, calc(i+ 1, j, pl^1)+ v[i]);
                        ret1= max(ret1, calc(i, j- 1, pl^1)+ v[j]);
                        return ret1;
                }else {
                        ret1= 1e18;
                        ret1= min(ret1, calc(i+ 1, j, pl^1)- v[i]);
                        ret1= min(ret1, calc(i, j- 1, pl^1)- v[j]);
                        return ret1;
                }
        };
        cout << calc(0, n- 1, 1);
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
