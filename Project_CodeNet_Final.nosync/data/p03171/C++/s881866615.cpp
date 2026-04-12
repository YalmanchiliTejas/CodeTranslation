#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)  
#define rep(i,n) for(long long int (i)=0;(i)<(n);++(i))
#define ref(i,a,b) for (long long int (i)=(a); (i)<=(b); ++(i))
#define INF 0xFFFFFF
#define endl '\n'
const unsigned int mod = 1e9+7;
const int maxInt = 2147483647;
const int mx=3005;
ll a[mx];
ll dp[mx][mx];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    rep(i,n)cin >> a[i];
    for(int i=n-1;i>=0;--i){
    	for(int j=i+1;j<=n;++j){
    		dp[i][j]=max(a[i]-dp[i+1][j],a[j-1]-dp[i][j-1]);
    	}
    }
    cout << dp[0][n];
    return 0;
}
