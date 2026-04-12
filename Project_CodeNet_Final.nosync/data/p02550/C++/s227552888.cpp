//#include<atcoder/all>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
//using namespace atcoder;

#define ll long long
#define pal pair<ll,ll>
#define pad pair<double,double>
#define PB push_back
#define MP make_pair
#define F first
#define S second

const ll MOD = 1e9+7;
const ll INF = 1e18;
const double EPS = 1e-8;

template<typename T,typename U>
bool chmax(T& max, const U& x){
	if(max<x){
		max = x;
		return true;
	}
	return false;
}

template<typename T,typename U>
bool chmin(T& min, const U& x){
	if(min>x){
		min = x;
		return true;
	}
	return false;
}

vector<ll> deta(100001,0);

int main(){
	ll n,x,m;
    bool f=false;
	cin >> n >> x >> m;
	vector<ll> loop(m,0);
	ll ls,le,lsize;
	ll tmp=x;
	for(ll i=1;i<=n;i++){
		if(i>1)tmp= (tmp*tmp);
		tmp %=m;
		if(deta[tmp]!=0){
			ls=deta[tmp];
			le=i-1;
			lsize=le-ls+1;
			break;
		}else{
			deta[tmp]=i;
			loop[i]=loop[i-1]+tmp;
		}
		if(i==n) f=true;
	}
	if(f){
		cout << loop[n] << endl;
	}else{
		ll sho = (n-ls+1)/lsize;
		ll amari=(n-ls+1)%lsize;
		cout << loop[ls-1]+(loop[le]-loop[ls-1])*sho+loop[amari+ls-1]-loop[ls-1] << endl;
	}
}