#include <bits/stdc++.h>
//#define DEBUG
#define REP(i, nn ) for(int i = 0 ; i < (int) nn; i++)
#define deb(x) std::cerr << #x << " " << x << endl;
#define debl(x) std::cerr << #x << " " << x << " ";
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
//const ll LINF = 1001002003004005006ll;
//const int INF = 1001001001;
template<typename... T>
void read(T& ... a){
    ((cin >> a),...);
}
template<typename... T>
void write(T... a){
    ((cout << a << "\n"),...);
}

template<typename... T>
void write_space(T... a){
    ((cout << a << " "),...);
}
// constexpr int MOD = 1e9 + 7;
constexpr int mxN = 3000;
ll dp[2][mxN][mxN];
void solve(){
    int n;
    read(n);
    vl a(n);
    REP(i,n) cin >> a[i];
    for(int d = 0; d < n ; d++){
        for(int i = 0 ; i < n - d; i++){
            int j = i + d;
            if( i == j){
                dp[0][i][j] = a[i];
                dp[1][i][j] = a[i];
                continue;
            }
            // Taro decision
            dp[0][i][j] = max(a[i] - dp[1][i+1][j], a[j] - dp[1][i][j-1]);

            // Jiro decisiont
            dp[1][i][j] = max(a[i] - dp[0][i+1][j], a[j] - dp[1][i][j-1]);
        }
    }
    cout << dp[0][0][n-1] << endl;
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/
    solve();
    return 0;
}

