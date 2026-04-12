#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef long long ll;

struct Union_Find {
    //各要素が属する集合の代表(根)を管理する
    //もし、要素xが根であればdata[x]は負の値を取り、-data[x]はxが属する集合の大きさに等しい
    vector<int> data;
    
    Union_Find(int size) : data(size, -1) {}
    bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        bool is_union = (x != y);
        if (is_union) {
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return is_union;
    }
    int Find(int x) {
        if (data[x] < 0) { //要素xが根である
            return x;
        } else {
            data[x] = Find(data[x]); //data[x]がxの属する集合の根でない場合、根になるよう更新される
            return data[x];
        }
    }
    bool same(int x, int y) {
        return Find(x) == Find(y);
    }
    int size(int x) {
        return -data[Find(x)];
    }
};


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<P> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> y[i].first;
		x[i].second = i;
		y[i].second = i;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	vector<T> e;
	for (int i = 0; i + 1 < n; i++) {
		e.emplace_back(x[i + 1].first - x[i].first, x[i + 1].second, x[i].second);
		e.emplace_back(y[i + 1].first - y[i].first, y[i + 1].second, y[i].second);
	}

	sort(e.begin(), e.end());

	ll ans = 0;
	Union_Find uf(n);
	for (T& t : e) {
		int c, u, v;
		tie(c, u, v) = t;
		if (uf.same(u, v)) continue;
		uf.Union(u, v);
		ans += c;
		if (uf.size(0) == n) break;
	}
	cout << ans << endl;
	return 0;
}