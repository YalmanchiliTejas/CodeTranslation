#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

const int INF=0x3f3f3f3f;
int n;
int a[100001],dp[100001];
int main(){
    cin>>n;
    rep(i,n) cin>>a[i];
    reverse(a,a+n);
    memset(dp,0x3f,sizeof(dp));
    rep(i,n){
        *upper_bound(dp,dp+n,a[i])=a[i];
    }
    cout<<lower_bound(dp,dp+n,INF)-dp<<endl;
    return 0;
}
