#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, ll> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

ll segtree[816225][2],s[225816];
bool delayed[816225];

void eval(int i, int l, int r){
	if(delayed[i]){
		segtree[i][0] += segtree[i][1];
		if(r-l>1){
			segtree[2*i+1][1] += segtree[i][1];
			delayed[2*i+1] = true;
			segtree[2*i+2][1] += segtree[i][1];
			delayed[2*i+2] = true;
		}
		segtree[i][1] = 0ll;
		delayed[i] = false;
	}
}

void update(int a, int b, int i, int l, int r, ll v){
	eval(i,l,r);
	if(b<=l || r<=a){
		return;
	}
	if(a<=l && r<=b){
		segtree[i][1] = v;
		delayed[i] = true;
		eval(i,l,r);
	}else{
		update(a,b,2*i+1,l,(l+r)/2,v);
		update(a,b,2*i+2,(l+r)/2,r,v);
		segtree[i][0] = max(segtree[2*i+1][0],segtree[2*i+2][0]);
	}
}


void update2(int a, int i, int l, int r, ll v){
	eval(i,l,r);
	if(!(l<=a && a<r)){
		return;
	}
	if(r-l>1){
		update2(a,2*i+1,l,(l+r)/2,v);
		update2(a,2*i+2,(l+r)/2,r,v);
		segtree[i][0] = max(segtree[i*2+1][0],segtree[i*2+2][0]);
	}else{
		segtree[i][0] = v;
	}
}

ll query(int a, int b, int i, int l, int r){
	ll vl,vr;
	if(b<=l || r<=a){
		return -INFLL;
	}
	eval(i,l,r);
	if(a<=l && r<=b){
		return segtree[i][0];
	}else{
		vl = query(a,b,2*i+1,l,(l+r)/2);
		vr = query(a,b,2*i+2,(l+r)/2,r);
		return max(vl,vr);
	}
}

vector<P> t[225816];

int main(void){
	int n,m,l,r,i,j;
	ll a,ans=0ll;
	fill(s,s+225816,0ll);
	fill(segtree[0],segtree[816225],0ll);
	fill(delayed,delayed+816225,false);
	cin >> n >> m;
	for(i=0; i<m; ++i){
		cin >> l >> r >> a;
		s[l] += a;
		t[r].push_back(P(l,a));
	}
	for(i=1; i<=n; ++i){
		update(0,i,0,0,n+1,s[i]);
		a = query(0,i,0,0,n+1);
		ans = max(a,ans);
		update2(i,0,0,n+1,a);
		for(j=(t[i].l_ength()-1); j>=0; --j){
			l = t[i][j].first;
			a = t[i][j].second;
			update(0,l,0,0,n+1,-a);
		}
	}
	cout << ans << endl;
	return 0;
}
