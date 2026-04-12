#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
 
//dp[i][j][k],i桁数,j:0を用いた数、k:最大かどうか?
bool vis[120][4][2];
lli dp[120][4][2];
string s;
 
lli calc(lli now,lli leftK,int maxFlag){
	if(vis[now][leftK][maxFlag])return dp[now][leftK][maxFlag];
	vis[now][leftK][maxFlag] = true;
	if(leftK==0){return dp[now][leftK][maxFlag]=1;
	}
	if(now>=s.size())return dp[now][leftK][maxFlag]=0;
	lli rtn=0;

	//maxフラグが立っている。
	if(maxFlag){
		//0をここで使う場合
		if(s.at(now)=='0')rtn += calc(now+1,leftK,1);
		else rtn += calc(now+1,leftK,0);
 
		//0以外を使う
		//さらにmaxをそのまま継続する場合
		if(s.at(now)!='0'){
			rtn += calc(now+1,leftK-1,1);
			rtn += (s.at(now)-'1')*calc(now+1,leftK-1,0);
		}
 
		//maxは継続させない場合
		//if(s.at(now)!=0)rtn += (s.at(now)-'1')*calc(now+1,leftK-1,0);
	}
	else{//maxを継続せずに9倍させる。
		//0を使う場合,leftKはそのままにする。
		rtn += calc(now+1,leftK,0);
		//0以外を使う場合,leftKを減らす
		rtn += 9 * calc(now+1,leftK-1,0);
	}
 
 	if(DEBUG)cout<<"now="<<now<<"leftK="<<leftK<<"maxFlag="<<maxFlag<<" rtn ="<<rtn<<endl;
	return dp[now][leftK][maxFlag] = rtn;
}
 
signed main(){
 
	lli k;
 
	cin>>s>>k;
 
 	calc(0,k,1);
 	if(dp[0][k][1]<0)cout<<0<<endl;
	else cout<<calc(0,k,1)<<endl;
 
	return 0;
}