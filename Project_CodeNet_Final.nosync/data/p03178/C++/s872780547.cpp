/*
 *  author: chw0501
 *  reference: 
 *  created: 24.04.2020 12:04:07(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007
#define INF 987654321 

string x;
int d,len;

//dp[i][j]: i개의 자릿수에 각각 0~9까지 들어갈 수 있고 그 전까지의 합이 j일 때의 가짓수 
ll dp[10010][100];

ll solve1(int i,int j){
	ll & ret=dp[i][j];
	if(ret!=-1ll) return ret;
	if(i==0){
		if(j==0) return ret=1;
		return ret=0;
	}
	ret=0;
	for(int k=0;k<10;k++){
		ret=(ret+solve1(i-1,(j+k)%d))%MOD;
	}
	return ret;
}

//앞에서 i번째 자릿수까지 x와 일치했을 때(지금까지의 합이 j) 앞으로 얻을 수 있는 가짓수
ll solve2(int i,int j){
	if(i==len-1){
		if(j==0) return 1;
		return 0;
	}
	ll ret=0;
	for(int k=0;k<(x[i+1]-'0');k++){
		ret=(ret+solve1(len-i-2,(j+k)%d))%MOD;
	}
	ret=(ret+solve2(i+1,(j+(x[i+1]-'0'))%d))%MOD;
	return ret;
}

int main(){
	cin>>x;
	cin>>d;
	len=x.size();
	memset(dp,-1ll,sizeof(dp));
	int y=x[0]-'0';
	ll ans=0;
	for(int i=0;i<y;i++) ans=(ans+solve1(len-1,i%d))%MOD;
	ans=(ans+solve2(0,y%d))%MOD;
	cout<<(ans+MOD-1)%MOD;
	return 0;
}