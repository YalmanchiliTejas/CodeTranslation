#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 1000000007;
constexpr int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long double PI = acos(-1.0);
// cout << fixed << setprecision(14);
 
signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if(N >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
}