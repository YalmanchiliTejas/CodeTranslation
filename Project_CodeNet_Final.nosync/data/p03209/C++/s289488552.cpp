#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define INF 9999999
#define LINF 99999999999
//#define ARRAY(type,n) (type *)malloc(sizeof(type)*n)
template<typename T>
T* ARRAY(int n){
	(T*)malloc(sizeof(T)*n);
}
template<typename T>
T** ARRAY2(int m,int n){
	T** type = (T**)malloc(sizeof(T*)*m);
	for(int i=0;i<m;i++){
		type[i]=(T*)malloc(sizeof(T)*n);
	}
	return type;
}

bool cmp(pair<ll,ll> l, pair<ll,ll> r){
	return l.first<r.first;
}

vector<ll> lnum;

vector<ll> memo;

//L_n = 2*L_(n-1) +3
ll func(int n, ll x){
	if(lnum[n]-1 <= x){
		return memo[n];
	}
	if(n==0){
		return 1;
	}
	if(x<=1){
		return 0;
	}
	ll retval = 0;
	if(x <= lnum[n-1]+1){
		return func(n-1,x-1);
	}
	retval += memo[n-1];
	retval += 1;
	if(x == lnum[n-1]+2){
		return retval;
	}
	retval += func(n-1,x-2-lnum[n-1]);
	return retval;
}


 
int main(void){
	ll n,x,tmp;
	cin>>n>>x;
	lnum.push_back(1);
	memo.push_back(1);
	rep(i,n){
		lnum.push_back(lnum[i]*2 + 3);
		memo.push_back(memo[i]*2 + 1);
	}
	cout<<func(n,x)<<endl;

	return 0;
}