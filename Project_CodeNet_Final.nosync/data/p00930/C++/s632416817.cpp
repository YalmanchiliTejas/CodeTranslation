#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

class RangeAddRangeMinTree {
public:
	vector<ll> node;
	vector<ll> add;
	ll sz;
	RangeAddRangeMinTree(vector<ll> v) {
		sz = 1;
		while(sz < v.size())sz *= 2;
		node = vector<ll>(2*sz,LLINF);
		add = vector<ll>(2*sz,0);
		for(int i = 0;i < v.size();i++){
			node[sz + i - 1] = v[i];
		}
		for(int i = node.size() - 1;i > 0;i--){
			node[(i - 1) / 2] = min(node[(i - 1) / 2],node[i]);
		}
	}

	void rangeAdd(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
		if(r == -1)r = sz;
		if (r <= a || b <= l) return;
		if (a <= l && r <= b){
			add[k] += x;
			return;
		}
		rangeAdd(a, b, x, k * 2 + 1, l, (l + r) / 2);
		rangeAdd(a, b, x, k * 2 + 2, (l + r) / 2, r);

		node[k] = min(node[k * 2 + 1] + add[k * 2 + 1], node[k * 2 + 2] + add[k * 2 + 2]);
	}

	ll getMin(int a, int b, int k = 0, int l = 0, int r = -1) {
		if(r == -1)r = sz;
		if (r <= a || b <= l) return (LLINF);
		if (a <= l && r <= b) return (node[k] + add[k]);

		ll left = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
		ll right = getMin(a, b, k * 2 + 2, (l + r) / 2, r);

		return (min(left, right) + add[k]);
	}
};

int main(){

	int n,q;cin >> n >> q;
	string str;cin >> str;
	set<int> s;
	vector<ll> v(str.size());
	int now = 0;
	for(int i = str.size()-1;i >= 0;i--){
		if(str[i] == '('){
			now--;
		}
		else{
			now++;
			s.insert(i);
		}
		v[i] = now;
	}
	RangeAddRangeMinTree seg(v);

	REP(seica,q){
		int t;cin >> t;t--;
		if(str[t] == '(') {
			str[t] = ')';
			seg.rangeAdd(0,t+1,2);
			s.insert(t);
			int ans = *s.begin();
			str[ans] = '(';
			seg.rangeAdd(0,ans+1,-2);
			cout << ans + 1 << endl;
			s.erase(s.begin());
		}
		else{
			str[t] = '(';
			auto it = s.lower_bound(t);
			s.erase(it);
			seg.rangeAdd(0,t+1,-2);
			int l = 0;
			int r = n;
			while(r - l > 1){
				int mid = (l + r) / 2;
				if(seg.getMin(mid, n+1) < 0) l = mid;
				else r = mid;
			}
			cout << l + 1 << endl;
			seg.rangeAdd(0,l+1,2);
			str[l] = ')';
			s.insert(l);
		}
	}

	return 0;
}

