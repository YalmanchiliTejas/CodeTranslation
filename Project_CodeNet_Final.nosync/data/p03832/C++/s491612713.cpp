#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
//const int MAX=;
const ll MOD=1e9+7;

int extgcd(int a,int b,int& x, int& y){
	int d=a;
	if(b!=0){
		d = extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return d;
}
int mod_inv(int a,int m){
	int x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

int main(){
	ll N,A,B,C,D;
	cin>>N>>A>>B>>C>>D;
	
	//階乗を持っておく
	ll fa[1002];
	fa[0]=1;
	rep1(i,N)fa[i]=(fa[i-1]*i)%MOD;
	
	//階乗のべきも持っておく(i!のj乗)
	ll fap[1002][1002];
	rep(i,N+1){
		fap[i][0]=1;
		rep1(j,N){
			fap[i][j]=(fap[i][j-1]*fa[i])%MOD;
		}
	}
	
	ll dp[1002][1002];
  	dp[A-1][0]=1;
	rep1(j,N)dp[A-1][j]=0;
	for(int i=A;i<=B;i++)rep(j,N+1){
		dp[i][j]=dp[i-1][j];
		rep1(k,j/i){
			if(!(C<=k && k<=D))continue;
			ll c=dp[i-1][j-i*k];
			c=(c*fa[N-j+i*k])%MOD;
			c=(c*mod_inv(fa[N-j],MOD))%MOD;
			c=(c*mod_inv(fa[k],MOD))%MOD;
			c=(c*mod_inv(fap[i][k],MOD))%MOD;
			dp[i][j]=(dp[i][j]+c)%MOD;
		}
	}
	cout<<dp[B][N];
}
