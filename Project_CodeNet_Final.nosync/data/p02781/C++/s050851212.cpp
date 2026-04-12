#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T>
inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int dp[200][5][2];

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    string N; cin >> N;
    int K; cin >> K;
    dp[0][0][0]=1;
    rep(i,SZ(N)){
        per(j,K+1){
            if(dp[i][j][1]>0){
                dp[i+1][j+1][1]+=9*dp[i][j][1];
                dp[i+1][j][1]+=dp[i][j][1];
            }
            if(N[i]!='0'){
                dp[i+1][j+1][1]+=dp[i][j][0]*((N[i]-'0')-1);
                dp[i+1][j+1][0]+=dp[i][j][0];
                dp[i+1][j][1]+=dp[i][j][0];
            } else {
                dp[i+1][j][0]+=dp[i][j][0];
            }
        }
    }
    cout << dp[SZ(N)][K][1]+dp[SZ(N)][K][0] << endl;
}