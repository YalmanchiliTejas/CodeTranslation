#include <bits/stdc++.h>
using namespace std;
string k;
long long d;
long long dp[100009][109][2];
long long mod = 1000000007;
long long bt(int id,int sum,int t){
	if(id==k.size()){
		return (sum%d == 0);
	}
	long long &ret=dp[id][sum][t];
	if(ret!=-1)return ret;
	ret=0;
	int r=9;
	if(t==1)r=k[id]-'0';
	for(int i=0;i<r;i++){
		ret=(ret+bt(id+1,(sum+i)%d,0))%mod;
	}
	ret=(ret + bt(id+1,(sum+r)%d,t))%mod;
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>k>>d;
	cout<<(bt(0,0,1)-1+mod)%mod<<endl;
}
