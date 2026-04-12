#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int dp[201][201][402];
int a[201][201];

int h,w;


int dfs(int x1,int x2,int k){
    if(~dp[x1][x2][k]) return dp[x1][x2][k];
    int ret = (x1==x2?a[k-x1][x1]:a[k-x1][x1]+a[k-x2][x2]);
    int t = 0;
    if(k==h+w) return ret;
    if(x1+1<w&&x2+1<w) chmax(t, dfs(x1+1,x2+1,k+1));
    if(k+1-x1<h&&x2+1<w) chmax(t, dfs(x1,x2+1,k+1));
    if(x1+1<w&&k+1-x2<h) chmax(t, dfs(x1+1,x2,k+1));
    if(k+1-x1<h&&k+1-x2<h) chmax(t, dfs(x1,x2,k+1));
    ret += t;
    return dp[x1][x2][k] = ret;
}



int main(){
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0) << endl;
    return 0;
}
