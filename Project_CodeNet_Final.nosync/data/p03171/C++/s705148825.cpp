#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000050;
typedef long long ll;
ll a[maxn];
ll dp[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			dp[j]=max(a[j]-dp[j+1],a[j+i-1]-dp[j]);
		}
	}
	cout<<dp[1]<<endl;
	return 0;
}