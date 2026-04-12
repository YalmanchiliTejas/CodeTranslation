#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, M;
    cin >> N >> M;
    bool cone[N][N];
    rep(i, N) rep(j, N) cone[i][j] = false;
    rep(i, M){
        int u, v;
        cin >> u >> v;
        u--, v--;
        cone[u][v] = true;
        cone[v][u] = true;
    }
    int ans = 0;
    vector<int> nums;
    rep(i, N) nums.pb(i);
    do{
        bool able = true;
        rep(i, N-1){
            if(!cone[nums[i]][nums[i+1]]) able = false;
        }
        if(nums[0] == 0 && able) ans++;
    } while(next_permutation(nums.begin(), nums.end()));
    cout << ans << endl;
}