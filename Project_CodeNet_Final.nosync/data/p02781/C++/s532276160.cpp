#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    string s;int K;
    cin >> s >> K;
    int n = s.length();
    int dp[n+1][2][4];
    repn(i,n)rep(j,2)rep(k,4) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i,n)repn(j,1)repn(k,K){
        int now = s[i] - '0';
        if(j==0){
            rep(l,10){
                int nk = k;
                if(l != 0) nk++;
                if(nk > K || now < l) continue;
                if(now==l) dp[i+1][0][nk] += dp[i][0][k]; 
                if(now > l) dp[i+1][1][nk] += dp[i][0][k];
            }
        }else if(j==1){
            rep(l,10){
                int nk = k;
                if(l != 0) nk++;
                if(nk > K) continue;
                dp[i+1][1][nk] += dp[i][1][k];
            } 
        }
    }
    ll ans = 0;
    repn(j,1) ans += dp[n][j][K];
    cout << ans << endl;

}