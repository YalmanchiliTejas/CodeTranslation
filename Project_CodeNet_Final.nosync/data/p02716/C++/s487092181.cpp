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
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};



int main(){
    int n;cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<LL>> dp(n, vector<LL> (3, -LINF));
    if(n%2){
        dp[2][1] = a[2];
        dp[1][0] = a[1];
        dp[0][2] = a[0];
        for (int i = 0; i < n; i++) {
            if(i+2<n){
                chmax(dp[i+2][2],dp[i][2]+a[i+2]);
                chmax(dp[i+2][1],dp[i][1]+a[i+2]);
                chmax(dp[i+2][0],dp[i][0]+a[i+2]);
            }
            if(i+3<n){
                chmax(dp[i+3][0],dp[i][2]+a[i+3]);
                chmax(dp[i+3][1],dp[i][0]+a[i+3]);
            }
            if(i+4<n){
                chmax(dp[i+4][1],dp[i][2]+a[i+4]);
            }
        }
        cout << max({dp[n-1][1],dp[n-2][0],dp[n-2][1],dp[n-3][2]}) << endl;
    }
    else{
        dp[1][1] = a[1];
        dp[0][0] = a[0];
        for (int i = 0; i < n; i++) {
            if(i+2<n){
                chmax(dp[i+2][1],dp[i][1]+a[i+2]);
                chmax(dp[i+2][0],dp[i][0]+a[i+2]);
            }
            if(i+3<n) chmax(dp[i+3][1],dp[i][0]+a[i+3]);
        }
        cout << max(dp[n-1][1],dp[n-2][0]) << endl;
    }
    return 0;
}

