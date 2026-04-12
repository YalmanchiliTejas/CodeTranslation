#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<ll, ll> 
#define pb push_back
#define debug(x) cerr<< #x << " is " <<x<<endl;
#define debug2(x) cerr<<#x<< " is\n"; for (auto &i:x) {cout<<i<<' '; } cout<<endl;
#define f first
#define s second
using namespace std;

ll dp[3005][3005][2];
ll ps[3005];
ll sum[3005][3005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++){
    	ps[i+1]=ps[i]+a[i];
    }
    for (int i=0; i<n; i++) {
    	for (int j=i; j<n; j++){
    		sum[i][j]=ps[j+1]-ps[i];
    	}
    }
    for (int i=0; i<n; i++){
    	for (int j=0; i+j<n; j++){
    		int k = i+j;
    		if (i==0) {
    			dp[j][k][0]=dp[j][k][1]=a[j];
    		}
    		dp[j][k][0]=max(a[j]+sum[j+1][k]-dp[j+1][k][1],
    						a[k]+sum[j][k-1]-dp[j][k-1][1]);
    		dp[j][k][1]=max(a[j]+sum[j+1][k]-dp[j+1][k][0],
    						a[k]+sum[j][k-1]-dp[j][k-1][0]);
    	}
    }
    cout<<dp[0][n-1][0]*2-sum[0][n-1]<<endl;
}