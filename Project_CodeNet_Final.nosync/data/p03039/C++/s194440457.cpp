#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()


//長さlの中にk個詰め込まれている場合の数(横)
//(l*m)Ck - ((l-1)*m)Ck * 2 + ((l-2)*mCk)
//これはn-l+1の自由度

//n*m-2 C k-2 を最後にかける
//m*m*(1*(n-1) + 2*(n-2) + 3*(n-3) + ... + (n-1) * 1)
//たてもやる

vector<ll> iCk;

ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==1){
		return (mpow(a,b-1) * a)%MOD;
	}else{
		ll ret = mpow(a,b/2);
		return (ret*ret)%MOD;
	}
}

int main(void){
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans = 0;
	ll sum = 0;
	reps(i,n-1){
		sum += i*(n-i);
		sum %= MOD;
	}
	sum *= m;
	sum %= MOD;
	sum *= m;
	sum %= MOD;
	ans += sum;

	sum = 0;
	reps(i,m-1){
		sum += i*(m-i);
		sum %= MOD;
	}
	sum *= n;
	sum %= MOD;
	sum *= n;
	sum %= MOD;
	ans += sum;

	ans %= MOD;
	rep(i,k-2){
		ans *= (n*m-2-i);
		ans %= MOD;
		ans *= mpow(k-2-i, MOD-2);
		ans %= MOD;
	}
	cout<<ans<<endl;


	return 0;
}
