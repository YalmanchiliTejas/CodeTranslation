#include<iostream>
using namespace std;
int n,s;
const long long mod=998244353;
int a[5000];
int dp[5000];
long long res=0;
int main()
{
	cin >> n >> s;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[0]++;
		for(int j=s;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		res=(res+dp[s])%mod;
	}
	cout << res;
	return 0;
}