#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;


//mod演算ライブラリ
//mod=1000000007

LL add(LL a,LL b){
  return (a+b)%mod;
}

LL sub(LL a,LL b){
  return (a+mod-b)%mod;
}

LL mul(LL a,LL b){
  return ((a % mod) * (b % mod)) % mod;
}

LL power(LL x,LL y){//繰り返し二乗法 単品利用可
  if(y==0)return 1;
  else if(y==1)return x%mod;
  else if(y%2==0){
    LL tmp=power(x, y/2) % mod;
    return tmp*tmp%mod;
  }else {
    LL tmp=power(x, y/2) % mod;
    return ((tmp*tmp)%mod)*x%mod;
  }
}

LL dvs(LL a,LL b){
  return mul(a,power(b,mod-2));
}

const int SIZE_mod=200005;
int invfact[SIZE_mod];
int fact[SIZE_mod];

LL factset(int a){//aまでの階乗%mod表を作成
  fact[0]=1;
  FORQ(i,1,a){
    fact[i]=mul(fact[i-1],i);
  }
}

LL cmbset(int a){//1~aまでの階乗と階乗数の逆元のmod(mod)を用意 O(a)
  factset(a);
  invfact[a]=power(fact[a],mod-2);
  invfact[0]=1;
  FORD(i,a,1){
    invfact[i]=mul(invfact[i+1],i+1);
  }

}

LL cmb(int n,int r){//nCr%mod  (cmbset後に使用)
  if(n<r||r<0||n<0)return 0;
  return mul(fact[n],mul(invfact[r],invfact[n-r]));
}

LL prm(int n,int r){//nPr%mod
    return mul(cmb(n,r),fact[n]);
}

LL homo(int n,int r){//nHr%mod
  return cmb(n+r-1,r);
}


int main(){
	string s;
	cin>>s;
	int d;
	cin>>d;
	int n=s.length();
	vector<LL> dp(d,0);
	vector<LL> dp2(d,0);
	vector<LL> dp3(d,0);
	vector<LL> dp4(d,0);
	dp[0]=1;
	FORD(rpt,n,0){
		int nw=s[rpt]-'0';
		FOR(i,0,d){
			FOR(j,0,nw+1){
				int nx=(i+j)%d;
				if(j==nw){
					dp2[nx]=add(dp[i],dp2[nx]);
					dp4[nx]=add(dp3[i],dp4[nx]);
					break;
				}
				dp2[nx]=add(dp[i],dp2[nx]);
				dp2[nx]=add(dp3[i],dp2[nx]);
			}

			FOR(j,nw+1,10){
				int nx=(i+j)%d;
				dp4[nx]=add(dp[i],dp4[nx]);
				dp4[nx]=add(dp3[i],dp4[nx]);
			}
		}
		swap(dp,dp2);
		dp2=vector<LL>(d,0);
		swap(dp3,dp4);
		dp4=vector<LL>(d,0);
	}
	cout<<sub(dp[0],1)<<endl;
    return 0;
}
