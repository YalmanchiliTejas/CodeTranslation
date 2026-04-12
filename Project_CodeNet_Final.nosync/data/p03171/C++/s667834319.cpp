#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
using ll=long long;

const int INF=1e9+5;
const int N=3000+5;
const int mod=1e9+7;

ll dp[N][N];

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	// freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	for(int l=n-1;l>=0;--l){
		for(int r=l;r<n;++r){
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	}
	cout<<dp[0][n-1];
	return 0;
}
		
