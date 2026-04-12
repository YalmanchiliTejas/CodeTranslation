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
lint dp[1010][1010],ink[1010][1010];
vector<lint> zyo;
lint extgcd(lint a, lint b, lint &x, lint &y) {
  lint g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
lint invMod(lint a, lint m) {
  lint x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
int main()
{
	lint mo=1000000007;
	zyo.pb(1);
	rep(i,1919) zyo.pb((zyo[i]*(i+1))%mo);
	rep(i,1005) ink[i][1]=invMod(zyo[i],mo);
	rep(i,1005) REP(j,1,1005) ink[i][j+1]=(ink[i][j]*ink[i][1])%mo;
	
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	memset(dp,0,sizeof(dp));
	dp[a][n]=1;
	REP(i,a,b+1) rep(j,n+1){
		if(dp[i][j]<0LL) cout<<i<<' '<<j<<endl;
		if(dp[i][j]<1LL) continue;
		//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		for(int k=c;k<=d && i*k<=j;k++){
			dp[i+1][j-i*k]+=(((dp[i][j]*ink[i][k])%mo*ink[k][1])%mo*zyo[j])%mo*ink[j-i*k][1];
			dp[i+1][j-i*k]%=mo;
		}
		dp[i+1][j]+=dp[i][j];dp[i+1][j]%=mo;
	}
	cout<<(dp[b+1][0]%mo)<<endl;
}
