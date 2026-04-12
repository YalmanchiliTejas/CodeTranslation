#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)

lli size[60]={0};
lli dp[60]={0};

lli calc(lli level,lli num){
	if(DEBUG)cout<<"level = "<<level<<" num="<<num<<endl;
	lli center = size[level]/2 + 1;
	if(level == 0)return 1;
	if(num == 1) return 0;
	else if(num < center)return calc(level-1,num-1);
	else if(num == center)return dp[level-1] + 1;
	else if(num == size[level])return dp[level];
	else return dp[level-1] + calc(level-1,num-center) + 1;
}

void init(){
	size[0]=1;
	dp[0]=1;
	for(lli i=1;i<60;i++){
		size[i] = 2*size[i-1]+3;
		dp[i] = 2*dp[i-1]+1;
		if(DEBUG)cout<<"i="<<i<<" size[i]="<<size[i]<<endl;
		if(DEBUG)cout<<"i="<<i<<" dp[i]="<<dp[i]<<endl;
	}
}

signed main(){

	lli n;
	lli x;
	cin>>n>>x;

	init();
	cout<<calc(n,x)<<endl;

	return 0;
}