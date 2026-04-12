#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<long double,long double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<pll,ll> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<62;
const double pi=acos(-1);
const long double eps=1e-7;
const ll mod=1e6+3;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
vi a,b,c;
vi res;

void f(int k){
	assert(0<k&&k<n);
	for(int i=k;i<n;i++){
		swap(a[i],a[i-k]);
		swap(b[a[i]],b[a[i-k]]);
	}
	res.push_back(k);
}

void Open(){
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	cout<<endl;
}

int main(){
	cin>>n;
	a=b=c=vi(n);
	int N=n/2;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]=i;
		c[i]=abs(N-i);
		if(n%2==0&&i<N) c[i]--;
	}
	if(n%2==1) while(a[N]!=N) f(1);
	for(int i=0;i<N;i++){
		int L=N-i-1,R=N+i+n%2;
		if(c[b[L]]!=c[b[R]]){
			int x=(c[b[L]]<c[b[R]]?L:R),y=L+R-x;
			f(N+c[b[x]]);
			if((b[L]<N)^(b[R]<N)) f(n-1);
			f(N+c[b[y]]+1);
			bool B=b[x]>=N,T=n%2==0&&!i;
			while(B&&b[y]||!B&&b[y]!=n-1) f(1);
			f(n-1);
			while(T&&c[b[x]]!=c[b[y]]||!T&&a[N]!=N) f(1);
		}
		f(max(b[L],b[R]));
		if(b[R]) f(n-1);
		f(R);
	}
	int S=res.size();
	cout<<S<<endl;
	for(int i=0;i<S;i++) cout<<res[i]<<endl;
}