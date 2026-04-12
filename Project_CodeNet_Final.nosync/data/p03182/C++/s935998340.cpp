#include <bits/stdc++.h>
    
using namespace std;
    
#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb push_back
#define fst first
#define snd second
    
typedef long long ll;

struct STree { // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]= max(st[2*k], st[2*k+1]); // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b), query(2*k+1,m,e,a,b)); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int n, m;

map<int, vector<pair<int, int>>> mp;

ll calc() {
    STree rmq(n + 1);
    ll q = 0;
    for(int i = n; i >= 0; i--) {
        for(auto p : mp[i + 1]) {
            rmq.upd(i + 1, p.fst, p.snd);
        }
        q = rmq.query(i + 1, n + 1);
        rmq.upd(i, i + 1, q);
        // cout << q << endl;
    }
    return q;
}

int main() {
    cin >> n >> m;
    fore(i, 0, m) {
        int l, r, a; cin >> l >> r >> a;
        mp[l].pb({r + 1, a});
    }
    cout << calc() << endl;
    return 0;
}