#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1 << 19;
const ll INF = 1LL << 50;

struct MinSegTree2{
	static const ll def = INF;
	int n;
	ll segMin[2 * MAX_N - 1], segAdd[2 * MAX_N - 1];
	void init(int n_){
		n = 1;
		while(n < n_) n *= 2;
		for(int i = 0; i < 2 * n - 1; i++) segMin[i] = def, segAdd[i] = 0;
	}

	void add(int a, int b, ll x){ add(a, b, x, 0, 0, n); }

	void add(int a, int b, ll x, int k, int l, int r){
		if(r <= a || b <= l) return;
		if(a <= l && r <= b){
			segAdd[k] += x;
			return;
		}
		add(a, b, x, k * 2 + 1, l, (l + r) / 2);
		add(a, b, x, k * 2 + 2, (l + r) / 2, r);
		segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
	}

	void set(int i, ll x){
		ll y = query(i, i + 1);
		add(i, i + 1, -y + x);
	}

	ll query(int a, int b){ return query(a, b, 0, 0, n); }

	ll query(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return def;
		if(a <= l && r <= b) return segMin[k] + segAdd[k];
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr) + segAdd[k];
	}
};

MinSegTree2 minst;

int N;
string s;

set<int> O, C;

void flip(int i){
	if(s[i] == '('){
		s[i] = ')';
		O.erase(i);
		C.insert(i);
		minst.add(i, N, -2);
	}
	else{
		s[i] = '(';
		C.erase(i);
		O.insert(i);
		minst.add(i, N, +2);
	}
}

void debug(){
	cout << s << endl;
	for(int i = 0; i < N; i++){
		cout << minst.query(i, i + 1) << " ";
	}
	cout << endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	int Q;
	cin >> N >> Q >> s;

	minst.init(N);
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(s[i] == '('){
			O.insert(i);
			cnt++;
			minst.set(i, cnt);
		}
		else{
			C.insert(i);
			cnt--;
			minst.set(i, cnt);
		}
	}

	//debug();

	while(Q--){
		int k;
		cin >> k;
		k--;
		char c = s[k];
		flip(k);
		//debug();
		int ans = k;

		if(c == '('){
			// CLOSE -> OPEN
			// ????????????CLOSE
			ans = *C.begin();
		}
		else{
			// OPEN -> CLOSE
			// [i, n) >= 2 ????????????????°????i
			int ng = 0, ok = k;
			while(abs(ng - ok) > 1){
				int mid = (ng + ok) / 2;
				auto it = O.lower_bound(mid);
				if(it == O.end()){
					ng = mid;
					continue;
				}
				int a = *it;
				if(minst.query(a, N) >= 2) ok = mid;
				else ng = mid;
			}
			ans = *O.lower_bound(ok);
		}

		cout << ans + 1 << endl;
		flip(ans);
		//debug();
	}
}