#include <bits/stdc++.h>
using namespace std;

#define op operator
#define pb push_back

struct poi {
	int x, y, z;
	poi op -(poi p) {
		return {x - p.x, y - p.y, z - p.z};
	}
	poi op +(poi p) {
		return {x + p.x, y + p.y, z + p.z};
	}
	bool op <(poi p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z);
	}
	vector <poi> rot() {
		int a[3] = {x, y, z};
		vector <poi> v;
		int p[3] = {0, 1, 2};
		do {
			int inv = (p[0] > p[1]) + (p[0] > p[2]) + (p[1] > p[2]);
			int x = a[p[0]], y = a[p[1]], z = a[p[2]];
			if(inv & 1) {
				v.pb({-x, y, z});
				v.pb({x, -y, z});
				v.pb({x, y, -z});
				v.pb({-x, -y, -z});
			} else {
				v.pb({x, y, z});
				v.pb({x, -y, -z});
				v.pb({-x, y, -z});
				v.pb({-x, -y, z});
			}
		}while(next_permutation(p, p + 3));
		return v;
	}
};

const int N = 1001;
bool v[N];
poi save[N];
vector <pair <poi, poi>> segs[2];

vector <pair <poi, poi>> read(int n) {
	poi p = {0, 0, 0};
	memset(v, 0, sizeof v);
	vector <pair <poi, poi>> r;
	for(int i = 0; i < n; i ++) {
		string s; cin >> s;
		if(s[0] == '+' || s[0] == '-') {
			poi q;
			if(s[1] == 'x')
				q = {1, 0, 0};
			else if(s[1] == 'y')
				q = {0, 1, 0};
			else
				q = {0, 0, 1};
			if(s[0] == '+')
				q = p + q;
			else
				q = p - q;
			r.pb({p, q});
			p = q;
		} else {
			int x = stoi(s);
			if(v[x])
				p = save[x];
			else {
				v[x] = 1;
				save[x] = p;
			}
		}
	}
	return r;
}

set <poi> st;
bool check(poi p) {
	bool v[24];
	memset(v, true, sizeof v);
	for(auto seg : segs[1]) {
		auto a = (seg.first - p).rot();
		auto b = (seg.second - p).rot();
		for(int i = 0; i < 24; i ++) {
			if(v[i] && !st.count(a[i] + b[i]))
				v[i] = false;
		}
		if(!count(v, v + 24, true))
			return false;
	}
	return count(v, v + 24, true);
}

int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	while(cin >> n) {
		if(n == 0) break;
		segs[0] = read(n);
		cin >> m;
		segs[1] = read(m);

		st.clear();
		for(auto seg : segs[0]) {
			poi p = seg.first - segs[0][0].first;
			poi q = seg.second - segs[0][0].first;
			st.insert(p + q);
		}

		bool f = false;
		for(auto seg : segs[1])
			f |= check(seg.first) || check(seg.second);
		cout << (f ? "SAME" : "DIFFERENT") << '\n';
	}
	return 0;
}