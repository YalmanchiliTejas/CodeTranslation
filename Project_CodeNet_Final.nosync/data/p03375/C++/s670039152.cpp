#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint mo;
lint dp[3010][3010];
lint co[3010][3010];
lint zyo[9001001];
lint zy2[3010];
int main()
{
	int n;
	cin>>n>>mo;
	rep(i,3005){
		co[i][0]=co[i][i]=1;
		REP(j,1,i) co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
	}
	memset(dp,0,sizeof(dp));dp[0][0]=1;
	rep(i,3005) rep(j,3005){
		if(i>0 && j>0) dp[i][j]+=dp[i-1][j-1];
		if(i>0) dp[i][j]+=dp[i-1][j]*(j+1);
		dp[i][j]%=mo;
	}
	zyo[0]=1;rep(i,9001000) zyo[i+1]=(zyo[i]*2)%mo;
	zy2[0]=2;rep(i,3005) zy2[i+1]=(zy2[i]*zy2[i])%mo;
	lint out=0;
	rep(i,n+1) rep(j,i+1){
		lint t=(dp[i][j]*co[n][i])%mo;
		t*=zyo[j*(n-i)];t%=mo;
		t*=zy2[n-i];
		//cout<<i<<' '<<j<<' '<<t<<endl;
		if(i%2==0) out+=t;else out-=t;out%=mo;
	}
	out%=mo;out+=mo;out%=mo;cout<<out<<endl;
}
