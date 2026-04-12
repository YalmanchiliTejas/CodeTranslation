
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
#include <stack>
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
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>

const double pi = 3.14159265358979323846264;
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

inline LL f(const LL a){
	return ((a+1)*a/2)%mod;
}

inline LL f2(const LL a,const LL d,const LL r){
	LL t=(a+d*(r-1))%mod;
	return ((t+a)*r/2)%mod;
}

int main(){
	 //cin.tie(0);
	//ios::sync_with_stdio(false);
	//std::cout << std::fixed;
	//std::cout << std::setprecision(12);
	//std::cout << std::defaultfloat;
	int n,m,k;
	cin>>n>>m>>k;
	vector<LL> t(m,0);
	FOR(i,0,m){
		LL l=i-0,r=m-1-i;
		t[i]=add(f(l),f(r));
		if(i>0)t[i]=add(t[i],t[i-1]);
	}

	LL ans=1,nm=mul(n,m),dv=1;
	FOR(i,0,k-2){
		ans=mul(ans,sub(nm-2,i));
		dv=mul(dv,i+1);
	}
	ans=dvs(ans,dv);//*/

	LL aa=0;
	FOR(i,0,n){
		LL u=i+1,dw=n-i;
		LL a=t[m-1],d=mul(m,m);
		aa=add(aa,sub(f2(a,d,u)+f2(a,d,dw),a));
	}
	aa=dvs(aa,2);
	//cerr<<t[m-1]<<endl;
	//cerr<<aa<<endl;
	cout<<mul(aa,ans);

	return 0;
}
