#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef pair<ll,pl> tl;
const int MN = 200200;
//Range Updates
//Maximum queries
class ST {
	private:
		int n,h;
		vl st,lz;
		const ll STV = -1LL<<62;
		//minimum start
		//const ll STV = 1LL<<62;
		int log2(int v) {
			if(v <= 1) return 1;
			return log2(v/2)+1;
		}
		void ap(int p, ll val) {
			st[p] += val;
			if(p < n) {lz[p] += val;}
		}
		void build(int p) {
			while(p > 1) {
				p >>= 1;
				if(p >= n) continue;
				st[p] = max(st[p<<1],st[p<<1|1])+lz[p];
			}
		}
		void psh(int p) {
			for(int s=h;s>0;s--) {
				int i = p>>s;
				if(lz[i] != 0) {
					ap(i<<1,lz[i]);
					ap(i<<1|1,lz[i]);
					lz[i] = 0;
				}
			}
		}
	public:
		ST(int _n) {
			n = _n;
			h = log2(n);
			st.assign(2*n,0);
			lz.assign(n,0);
		}
		void up(int l, int r, ll val) {
			if(l >= r) return;
			l += n;r += n;
			int li = l,ri = r;
			for(;l<r;l>>=1,r>>=1) {
				if(l&1) {ap(l++,val);
				}
				if(r&1) {ap(--r,val);
				}
			}
			build(li);build(ri-1);
		}
		ll qu(int l, int r) {
			l += n;r += n;
			psh(l);psh(r-1);
			ll res = STV;
			for(;l<r;l>>=1,r>>=1) {
				if(l&1) {res = max(res,st[l++]);}
				if(r&1) {res = max(res,st[--r]);}
			}
			return res;
		}
};
pl ro[MN];
ll lo[MN];
ll va[MN];

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin >> n >> m;
	ST st(n+2);
	for(int i=0;i<m;i++) {
		ll l,r,v;
		cin >> l >> r >> v;
		va[i] = v;
		lo[i] = l;
		ro[i] = {r,i};
	}
	sort(ro,ro+m);
	int id = 0;
	for(int i=1;i<=n+1;i++) {
		while(id < m && ro[id].first < i) {
			int idx = ro[id].second;
			int lf = lo[idx];
			int rt = ro[id].first;
			st.up(lf,rt+1,va[idx]);
			id++;
		}
		ll nx = st.qu(0,i);
		st.up(i,i+1,nx);
	}
	ll res = st.qu(0,n+2);
	cout << res << '\n';
}
