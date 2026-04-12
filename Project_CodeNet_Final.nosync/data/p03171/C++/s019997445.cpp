#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=100000000000000000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll dp[n][n];
    rep(i,n) dp[i][i]=a.at(i);
    for (int i=1;i<n;i++){
        rep(j,n-i){
            dp[j][j+i]=max(a.at(j)-dp[j+1][j+i],a.at(j+i)-dp[j][j+i-1]);
        }
    }
    cout << dp[0][n-1] << endl;
}
