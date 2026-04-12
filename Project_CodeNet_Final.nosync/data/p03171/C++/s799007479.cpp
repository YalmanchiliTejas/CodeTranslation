// I am Varun Das from Jadavpur University
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define dbg(x) cerr << #x << " = " << x << endl
#define INF LLONG_MAX
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
ll n,a[10004];
cin>>n;
ll dp[3004][3004];
memset(dp,0,sizeof(dp));
loop(i,0,n) cin>>a[i];
rep(i,n-1,0){
    loop(j,i,n){
        if(i==j) dp[i][j] = a[i];
        else{
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
}
cout<<dp[0][n-1];
	return 0;
}