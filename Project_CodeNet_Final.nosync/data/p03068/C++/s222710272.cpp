//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
using ll=long long;
using intpair=pair<int,int>;
using intpv=vector<intpair>;
using llpair=pair<ll,ll>;
using llpv=vector<llpair>;
using intvec=vector<int>;
using llvec=vector<ll>;
using intq=queue<int>;
using llq=queue<ll>;
using intmat=vector<intvec>;
using llmat=vector<llvec>;
using pairmat=vector<llpv>;
#define PI 3.141592653589793
#define INTINF 1<<30
#define LLINF 1LL<<60
#define MPRIME 1000000007
#define pqueue priority_queue
#define pushb push_back
#define all(name) name.begin(),name.end()
#define matrix(T) vector<vector<T>>
#define ABS(x) ( (x)>0 ? (x) : -(x) )
#define gsort(vbeg,vend) sort(vbeg,vend,greater<>())
#define init(a,v) for(auto &a: v)

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

ll GCD(ll a, ll b) { //最大公約数
	if(a==0||b==0) return 0;
	if(a<b) swap(a,b);
	ll tmp = a%b;
	while(tmp!=0) {
		a = b;
		b = tmp;
		tmp = a%b;
	}
	return b;
}

ll binpow(ll a, ll ex, ll p) { //繰り返し二乗法
	ll result=1LL;
	while(ex>0) {
		if(ex&1) result=result*a%p;
		ex>>=1;
		a=a*a%p;
	}
	return result;
}

ll Fact(ll x) { //階乗
	ll f=1;
	for(ll i=2; i<=x; i++) {
		f*=i;
	}
	return f;
}

ll nPr(ll n, ll r) {
	if(n<r) return 0;

	ll result=1LL;
	for(ll i=0; i<r; i++) result*=n-i;
	return result;
}

ll nPrP(ll n, ll r, ll p) { // mod pにおけるnPr
	if(n<r) return 0;

	ll result=1LL;
	for(int i=0; i<r; i++) {
		result*=n-i;
		result%=p;
	}
	return result;
}

ll nCr(ll n, ll r) {
	if (n == r) { return 1; }
	if (r > n) { return 0; }

	if (r > n / 2) { r = n - r; }

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }

	double result = 1;
	for (double i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
	}

	return (ll)result;
}

llvec fact,inv,factinv;
void prenCrP(ll n, ll p) {
	fact.resize(n+1);
	inv.resize(n+1);
	factinv.resize(n+1);
	fact[0]=fact[1]=inv[1]=factinv[0]=factinv[1]=1LL;
	for(ll i=2LL; i<=n; i++) {
		fact[i]=fact[i-1]*i%p;
		inv[i]=p-inv[p%i]*(p/i)%p;
		factinv[i]=factinv[i-1]*inv[i]%p;
	}
}
ll nCrP(ll n, ll r, ll p) { // mod pにおけるnCr
	if (r > n) return 0;
	return fact[n]*factinv[r]%p*factinv[n-r]%p;
}

ll LowerBinarySearch(llvec array, ll key, ll max, ll min) { //にぶたんlower
	if(max>min) {
		return -1LL;
	} else {
		ll mid = max + (min-max)/2;
		if(array[mid]>key) {
			return LowerBinarySearch(array,key,max,mid-1);
		} if(array[mid]<key) {
			return LowerBinarySearch(array,key,mid+1,min);
		} else {
			return mid;
		}
	}
}

ll GreaterBinarySearch(llvec array, ll key, ll max, ll min) { //にぶたんgreater
	if(max>min) {
		return -1LL;
	} else {
		ll mid = max + (min-max)/2;
		if(array[mid]<key) {
			return GreaterBinarySearch(array,key,max,mid-1);
		} if(array[mid]>key) {
			return GreaterBinarySearch(array,key,mid+1,min);
		} else {
			return mid;
		}
	}
}

int DigitNum(ll n) { //桁数
	int digit=0;
	ll wari=1LL;
	while(n/wari) {
		digit++;
		wari*=10;
	}
	return digit;
}

bool IsPrime(ll num) { //素数判定
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (ll i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

vector<ll> Divisor(ll x) { // 約数列挙
	vector<ll> result;
	ll i=1LL;
	for( ; i*i<x; i++) {
		if(x%i) continue;
		result.push_back(i);
		result.push_back(x/i);
	}
	if(i*i==x&&x%i==0)
		result.push_back(i);
	
	sort(result.begin(),result.end());
	return result;
}

vector<llpair> PrimeFact(ll x) { // 素因数分解 {素因数,指数}
	vector<llpair> result;
	ll ex=0LL;
	if(x%2==0) {
		while(x%2==0) {
			x/=2;
			ex++;
		}
		result.push_back({2,ex});
	}

	for(ll i=3LL; i*i<=x; i+=2) {
		if(x%i) continue;

		ex=0LL;
		while(x%i==0) {
			x/=i;
			ex++;
		}
		result.push_back({i,ex});
	}

	if(x!=1) result.push_back({x,1});

	return result;
}

bool Palind(string s) { //回文判定
	return s == string(s.rbegin(), s.rend());
}

struct Union_Find{
	vector<int> parent;
	vector<int> num;

	Union_Find(int N) : parent(N),num(N,1) {
		for(int i=0; i<N; i++) {
			parent[i]=i;
		}
	}

	int root(int x) {
		if(parent[x]==x) return x;
		return parent[x]=root(parent[x]);
	}

	void merge(int x, int y) {
		int xrt=root(x);
		int yrt=root(y);
		if(xrt==yrt) return ;
		parent[xrt]=yrt;
		num[yrt]+=num[xrt];
	}

	bool same(int x, int y) {
		return root(x)==root(y);
	}

	int size(int x) {
		return num[root(x)];
	}
};




int main() {
	int N; cin>>N;
	string S; cin>>S;
	int K; cin>>K; K--;
	char ch=S[K];

	for(int i=0; i<N; i++) {
		if(S[i]==ch)
			cout<<ch;
		else
			cout<<"*";
	}
	cout<<endl;
}
