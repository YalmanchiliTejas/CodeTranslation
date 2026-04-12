#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

ll dp[3005][3005];

void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    for(int i=n-1;i>=0;--i){//更新順に注意
        for(int j=i+1;j<=n;++j){
            if((n-(j-i))%2==0) dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
            else dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
        }
    }
    cout<<dp[0][n]<<"\n";
}
 
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
