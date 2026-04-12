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

long long MODPOW(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

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


int main(){
	ll x;
    cin >> x;
    if(x>=30){
        cout <<"Yes" <<endl;
    }else{
        cout << "No" << endl;
    }
}