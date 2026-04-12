#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <functional>

using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
long Pow(long x,long r){
	if(r == 0){
		return 1;
	}
	if(r % 2){
		return Pow(x,r-1) * x % mod;
	}
	else{
		long t = Pow(x,r/2);
		return t*t%mod;
	}
}
void Calc(){
	long H = rei();
	long W = rei();
	long K = rel();
	if(K-2 >= mod){
		cout << 0 << endl;
		return;
	}
	long ans = 1;
	for(int i=2;i<K;i++){
		ans *= (H*W-i);
		ans %= mod;
	}
	long c2 = 1;
	for(int i=1;i<=K-2;i++){
		c2 *= i;
		c2 %= mod;
	}
	ans *= Pow(c2,mod-2);
	ans %= mod;
	long c = 0;
	for(int i=1;i<H;i++){
		c += (H-i) * W * W % mod * i;
		c %= mod;
	}
	for(int i=1;i<W;i++){
		c += (W-i) * H * H % mod * i;
		c %= mod;
	}
	cout << ans * c % mod << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}