#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[110][5][2];
int k;
vector<int>num;
ll solve(int pos,int K,int flag)
{
	if(pos==(int)num.size()){
		if(K==k){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(K>k){
		return 0;
	}
	if(dp[pos][K][flag]!=-1){
		return dp[pos][K][flag];
	}
	ll sum = 0;
	int lmt;
	if(flag==0){
		lmt = num[pos];
	}
	else{
		lmt = 9;
	}
	for(int i=0;i<=lmt;i++){
		int nflag,nk = K;
		if(flag==1){
			nflag = 1;
		}
		else{
			if(i==lmt){
				nflag = 0;
			}
			else{
				nflag = 1;
			}
		}
		if(i!=0){
			nk++;
		}
		sum += solve(pos+1,nk,nflag);
	}
	return dp[pos][K][flag] = sum;
}
int main()
{
	string N;
	cin >> N >> k;
	for(auto it:N)
	{
		num.push_back(it-48);
	}
	memset(dp,-1,sizeof dp);
	printf("%lld\n",solve(0,0,0));
}
