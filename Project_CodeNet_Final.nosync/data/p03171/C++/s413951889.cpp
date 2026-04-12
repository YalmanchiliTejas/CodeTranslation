#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll getMaxscoreForPlayerOne(vector<ll> inp,vector<ll> runningSum,int n) {
	ll res=0;
	vector<vector<ll>> dp(n,vector<ll>(n,0));
	for(int i=0;i<n;i++)dp[i][i]=inp[i];
	for(int size=2;size<=n;size++) {
		for(int i=0;i<n-size+1;i++) {
			ll subSequenceSum=runningSum[size+i]-runningSum[i];
			if(subSequenceSum-dp[i][size+i-2]>subSequenceSum-dp[i+1][size+i-1]) {
				dp[i][size+i-1]=subSequenceSum-dp[i][size+i-2];
			} else {
				dp[i][size+i-1]=subSequenceSum-dp[i+1][size+i-1];
			}
		}
	}
	/*
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	res=dp[0][n-1];
	return res;
}

ll getScoreDifference(vector<ll> inp,int n) {
	ll res=0;
	vector<ll> runningSum(n+1,0);
	for(int i=1;i<n+1;i++) {
		runningSum[i]=runningSum[i-1]+inp[i-1];
	}
	res=getMaxscoreForPlayerOne(inp,runningSum,n);
	res=res-(runningSum[n]-res);
	return res;
}

int main() {
	int n=0;
	cin>>n;
	vector<ll> inp(n,0);
	for(int i=0;i<n;i++) cin>>inp[i];
	cout<<getScoreDifference(inp,n)<<endl;
	return 0;
}