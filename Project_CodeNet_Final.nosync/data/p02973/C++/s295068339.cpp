#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define F first
#define S second
#define mod 1000000007
#define INF 9000000000000000000
signed main(void){
    int dp[100010];
    int n;cin>>n;
    fill(dp,dp+n,INF);
    vector<int>V(n);rep(i,n)cin>>V[i];
    reverse(all(V));
    rep(i,n){
        int x=V[i];
        *upper_bound(dp,dp+n,x)=x;
    }
    cout<<lower_bound(dp,dp+n,INF)-dp<<endl;
}

