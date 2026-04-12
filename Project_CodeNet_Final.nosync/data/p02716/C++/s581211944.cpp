#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const int maxn=1e9+7;
int main(){
	int n;
	cin>>n;
	vector<ll>a(n+10,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<ll>dp(n+10,0);
	vector<ll>pre_sum(n+10,0);
	pre_sum[1]=a[1];
	for(int i=2;i<=n;i++){
		pre_sum[i]=pre_sum[i-2]+a[i];
	}
	//注意：dp[1]为0，因为dp[3]表示的含义是有三个元素，只要取一个，所以要么取3，要么不取三，那么结果就是dp[2]
	for(int i=2;i<=n;i++){
		if(i&1){//如果是奇数的话
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);//如果奇数不选的情况下，一定是dp[i-1]中找，因为剩下是偶数个，i-1可以选择，以上可以不用选择的。。。
		}else{
			dp[i]=max(dp[i-2]+a[i],pre_sum[i-1]);//偶数不选的时候，前面还有奇数个元素，那么如果要选择出一半元素，前面每隔一个是必须选择的，所以是pre_sum[i-1]
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}