//g++ -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC contest.cpp

#include <bits/stdc++.h>

// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #define _FORTIFY_SOURCE 2

using namespace std;
#define int long long
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define PI 3.1415926535897932384626433832795
int MOD=1e9+7;
int powmod(int a,int l, int md){a%=md; int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
int binpow(int a,int l){int res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
int invmod(int a, int md){return powmod(a,md-2,md);}
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef vector<int> vi; typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector< pair<ll,ll> > vll;
#define pb push_back
int __set(int b, int i) {return b|(1LL<<i);} //set ith bit
int __unset(int b, int i) {return b&(~(1UL<<i));}
int __check(int b, int i) {return b&(1LL<<i);} //returns 0 if ith bit is 0
int mulmod(int a, int b, int md) {return ((a%md)*(b%md))%md;}
int addmod(int a, int b, int md) {return (a+b)%md;}
int submod(int a, int b, int md) {return (((a-b)%md)+md)%md;}
int divmod(int a, int b, int md) {return mulmod(a, powmod(b, md-2, md), md);} //if md is prime;
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
priority_queue<int, vector<int>, greater<int> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class SegmentTree {
private:
	int n; vii st; vi lz; vi a;
	void merge(int node) {
		st[node].ss=st[2*node].ss+st[2*node+1].ss;
	}
	void build(int node, int lo, int hi) {
		if(lo==hi) {
			st[node]={lo,a[lo]};
			return;
		}
		build(2*node,lo,(lo+hi)/2);
		build(2*node+1,(lo+hi)/2+1,hi);
		merge(node);
	}
	void propagate(int node, int l, int r) {
		if(l!=r) {
			lz[2*node] += lz[node];
			lz[2*node+1] += lz[node];
		}
		st[node].ss += (r-l+1)*(lz[node]);
		lz[node]=0;
	}
	void update(int node, int l, int r, int lo, int hi, int val) {
		if(lz[node]!=0)
			propagate(node,l,r);
		if(hi < l || lo > r)
			return;
		if(hi >= r && lo <= l) {
			lz[node]+=val;
			propagate(node,l,r);
			return;
		}
		update(2*node,l,(l+r)/2,lo,hi,val);
		update(2*node+1,(l+r)/2+1,r,lo,hi,val);
		merge(node);
	}
	ii rmq(int node, int l, int r, int lo, int hi) {
		// cout<<l<<" "<<r<<" "<<lo<<" "<<hi<<endl;
		if(lz[node]!=0)
			propagate(node,l,r);
		if(hi < l || lo > r)
			return {-1, 0};
		if(hi >= r && lo <= l)
			return st[node];
		ii d1 = rmq(2*node, l, (l+r)/2, lo, hi);
		ii d2 = rmq(2*node+1, (l+r)/2+1, r, lo, hi);
		return {-1, d1.ss+d2.ss};
	}
public:
	SegmentTree(vi& __a) {
		n = __a.size();
		a=__a;
		st.assign(4*n,{0,0});
		lz.assign(4*n,0);
		build(1,0,n-1);
	}
	void Update(int l, int r, int val) {return update(1,0,n-1,l,r,val);}
	ii RMQ(int l, int r) {return rmq(1,0,n-1,l,r);}
};

signed main(void)
{
	IOS;

	string s; cin>>s;
	int na=0,nb=0;
	for(int i = 0; i < 3; i++) {
		if(s[i]=='A') na++;
		else nb++;
	}
	if(na == 2 || na==1)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl; 


	time();
	return 0;
}