#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef pair<int,int> PI; 
typedef pair<LL,LL> PLL;
typedef unsigned long long ULL;
typedef pair<double,double> PD;

#define FOR(x, b, e) for(int x = b; x<= (e); x++)
#define FORD(x, b, e) for(int x = b; x>= (e); x--)
#define REP(x, n) for(int x = 0; x<(n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define IN insert
#define ST first
#define ND second
#define INF 2000000011
#define MOD 1000000007

#define MAXS 2000100
#define MAXT 5243000

PLL tree[MAXT]; //{max,nakl}

vector<PLL> zb[MAXS];
vector<LL> mk[MAXS];

LL wyn=0;
int n,m;

void upd(int v,int a,int b,int l,int r,LL val){
	
	if(a>r||b<l||v>=MAXT)
		return;
		
	if(l<=a&&b<=r){
		tree[v].ST+=val;
		tree[v].ND+=val;
		return;
	}

	tree[v*2].ND+=tree[v].ND;
	tree[v*2+1].ND+=tree[v].ND;
	tree[v*2].ST+=tree[v].ND;
	tree[v*2+1].ST+=tree[v].ND;
	tree[v].ND=0;
	
	int sr=(a+b-1)/2;
	upd(v*2,a,sr,l,r,val);
	upd(v*2+1,sr+1,b,l,r,val);
	
	tree[v].ST=max(tree[2*v+1].ST,tree[2*v].ST);	
}

LL query(int v,int a,int b,int l,int r){
	
	if(a>r||b<l||v>=MAXT)
		return LONG_LONG_MIN;
	
	if(l<=a&&b<=r)
		return tree[v].ST;
	
	tree[v*2].ND+=tree[v].ND;
	tree[v*2+1].ND+=tree[v].ND;
	tree[v*2].ST+=tree[v].ND;
	tree[v*2+1].ST+=tree[v].ND;
	tree[v].ND=0;
	
	int sr=(a+b-1)/2;
	return max(query(v*2,a,sr,l,r),query(v*2+1,sr+1,b,l,r));	
}



int main(){ 
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	
	int szer=1;
	while(szer<=n)
		szer*=2;
	szer*=2;
		
	REP(I,m){
		int t1,t2,a1;
		cin>>t1>>t2>>a1;
		zb[t2].PB({t1,a1});
		mk[t1].PB(a1);
	}
	
	LL wyn=0;
	
	FOR(i,1,n){
		
		for(auto x:mk[i])
			upd(1,0,szer-1,0,i-1,x);
			
		LL val=query(1,0,szer-1,0,i-1);
		wyn=max(wyn,val);
		upd(1,0,szer-1,i,i,val);
		
		for(auto x:zb[i]) 
			upd(1,0,szer-1,0,x.ST-1,-x.ND);
		
	}
	
	cout<<tree[1].ST;
		
	return 0;
}
