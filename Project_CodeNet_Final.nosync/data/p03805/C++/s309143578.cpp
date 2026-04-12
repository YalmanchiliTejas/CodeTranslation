#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cstdint>
#include <cmath>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define Rep(i, n) for (long long i = 0; i< (long long)(n); i++)
#define RRep(i,n) for (long long i = ((long long)(n)-1); i>=0; i--)

struct Edge{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w){ }
};

using Graph = vector<vector<Edge>>;
using graph = vector<vector<int>>;

template <class T>
inline bool chmin(T &a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
T gcd(T a, T b){
    if( b==0 ) return a;
    else return gcd(b, a%b);
}

template <class T>
T lcm(T a, T b){
    return (a*b)/gcd(a,b);
}

int INF = 1e9+7;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> r(n,vector<int>(n,0));
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        r[a][b]++;
        r[b][a]++;
    }
    vector<vector<int>> dp(pow(2,n),vector<int>(n,INF));
    dp[pow(2,0)][0] = 1;
    for(int i = 1; i<pow(2,n); i++){
        rep(j,n){
            if(dp[i][j]==INF) continue;
            rep(k,n){
                if(r[j][k]==0) continue;
                int c = pow(2,k);
                if((i|c)==i) continue;
                if(dp[i|c][k]==INF){
                    dp[i|c][k] = dp[i][j];
                }
                else{
                    dp[i|c][k] += dp[i][j] ;
                }
            }
        }
    }
    int ans = 0;
    rep(i,n-1){
        if(dp[pow(2,n)-1][i+1]==INF) continue;
        ans += dp[(1<<n)-1][i+1];
    }
    cout << ans << endl;
}