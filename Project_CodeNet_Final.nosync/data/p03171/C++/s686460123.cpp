#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define forn(i,a,b) for(long long i=a;i<=b;i++)
#define fork(i,a,b,k) for(long long i=a;i<=b;i+=k)
using namespace std;
typedef long long ll;
ll n,a[3005],dp[3005][3005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=n;l>=1;l--){
		for(int r=l;r<=n;r++){
			if(l==r){
				dp[l][r]=a[l];
			}
			else {
				dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
			}
		}
	}
	cout<<dp[1][n];
}
