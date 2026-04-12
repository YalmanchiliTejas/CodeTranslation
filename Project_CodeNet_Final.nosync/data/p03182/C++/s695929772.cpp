#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#ifdef _debug
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) //
#endif
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
using db = double;
const int maxn = 400000;
struct seg{
	int l, r;
	ll v;
	friend bool operator < (const seg &a, const seg &b){
		return a.r < b.r;
		return a.r == b.r ? a.l < b.l : a.r < b.r;
		return a.l != b.l ? a.l < b.l : a.r < b.r;
	}
	friend istream& operator >> (istream& c, seg &a){
		return c >> a.l >> a.r >> a.v;
	} 
}se[maxn];
int n, m;
struct sgt{
	ll v[maxn << 1], tag[maxn << 1];
	void push(int i){
		v[i] += tag[i];
		if((i<<1|1) < (maxn<<1)){
			tag[i<<1] += tag[i];
			tag[i<<1|1] += tag[i];
		}
		tag[i] = 0;
	}
	void add_max(int ml, int mr, ll nv, int l = 0, int r = n, int i = 1){
		push(i);
		if(ml > r || mr < l)return;
		if(ml <= l and mr >= r)tag[i] += nv, push(i);
		else{
			add_max(ml, mr, nv, l, (l+r)/2, i<<1);
			add_max(ml, mr, nv, (l+r)/2+1, r, i<<1|1);
			v[i] = max(v[i<<1], v[i<<1|1]);
		}
	}
	ll qmax(int ml, int mr, int l = 0, int r = n, int i = 1){
		if(ml > r || mr < l)return -(1ll << 59);
		push(i);		
		if(ml <= l and mr >= r)return v[i];
		return max(qmax(ml, mr, l, (l+r)/2, i<<1), qmax(ml, mr, (l+r)/2+1, r, i<<1|1));
	}
}dp;
vector<seg> ss[maxn];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m;++i)cin >> se[i];
	for(int i = 0;i < m;++i)ss[se[i].r].push_back(se[i]);
	for(int i = 1;i <= n+1;++i){
		for(auto &k : ss[i-1])dp.add_max(k.l, i-1, k.v);
		ll nv = dp.qmax(0, i-1);
		if(i == n+1)cout << nv << '\n';
		else dp.add_max(i, i, nv);
	}
}