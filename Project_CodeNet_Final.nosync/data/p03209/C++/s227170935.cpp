#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 1000000007;
constexpr int INF = numeric_limits<int>::max() / 2;
// typedef pair<int,int> P;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const double PI = acos(-1.0);
// cout << fixed << setprecision(14);

int len[52], P[52];
int dfs(int n, int x){
    if(n == 0) return 1;
    if(x == 1) return 0;
    if(x <= len[n-1]+1) return dfs(n-1, x-1);
    if(x == len[n-1]+2) return P[n-1]+1;
    if(x <= len[n-1]*2+2) return P[n-1]+1+ dfs(n-1, x-len[n-1]-2);
    return P[n];
}
 
signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

    int N, X;
    cin >> N >> X;
    len[0] = 1;
    P[0] = 1;
    for(int i=1;i<=50;i++){
        len[i] = len[i-1]*2+3;
        P[i] = P[i-1]*2+1;
    }
    cout << dfs(N, X) << endl;
}