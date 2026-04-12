#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename T> struct CoordinateCompression
{
	const vector<T> &vals;
	map<T, int> zip;
	vector<T> unzip;
	int size_comp;

	CoordinateCompression(const vector<T> &vals) : vals(vals) {}

	void calc() {
		vector<T> vals(this->vals);
		sort(vals.begin(), vals.end());
		vals.erase(unique(vals.begin(), vals.end()), vals.end());
		size_comp = vals.size();
		unzip.resize(size_comp);
		for (int i = 0; i < size_comp; i++) {
			zip[vals[i]] = i;
			unzip[i] = vals[i];
		}
	}

	vector<int> compression(const vector<T> &v) {
		vector<int> res(v.size());
		for (int i = 0; i < v.size(); i++) {
			res[i] = zip[v[i]];
		}
		return res;
	}
};

template<class M> struct SegmentTree
{
	int n;
	int size;
	vector<M> data;
	const function<M(M, M)> op;
	const M ID;

	SegmentTree(int n, function<M(M, M)> op, M id, const vector<M> &init_vals=vector<M>()) : n(n), op(op), ID(id) {
		size = 1;
		while (size < n) size <<= 1;
		data.assign(size * 2, ID);
		for (int i = 0; i < init_vals.size(); i++) data[size+i] = init_vals[i];
		for (int i = size-1; i > 0; i--) data[i] = op(data[2*i], data[2*i+1]);
	}

	void init(const vector<M> &init_vals) {
		data.assign(size * 2, ID);
		for (int i = 0; i < init_vals.size(); i++) data[size+i] = init_vals[i];
		for (int i = size-1; i > 0; i--) data[i] = op(data[2*i], data[2*i+1]);
	}

	void update(int idx, M x) {
		idx += size;
		data[idx] = x;
		while (idx /= 2) {
			data[idx] = op(data[2*idx], data[2*idx+1]);
		}
	}

	M query(int l, int r) {
		M L = ID, R = ID;
		for (l += size, r += size; l < r; l /= 2, r /= 2) {
			if (l & 1) L = op(L, data[l]), l++;
			if (r & 1) r--, R = op(data[r], R);
		}
		return op(L, R);
	}

	M val(int idx) {
		return data[size + idx];
	}

	vector<M> val_vec() {
		vector<M> res(n);
		for (int i = 0; i < n; i++) res[i] = data[size+i];
		return res;
	}
};

template<typename T> int LIS_leq(vector<T> v) {
	CoordinateCompression<T> C(v);
	C.calc();
	vector<int> c = C.compression(v);
	auto op = [](int x, int y) {
		if (y > x) return y;
		return x;
	};
	SegmentTree<int> dp(C.size_comp, op, 0);
	int res = 0;
	for (int e : c) {
		int a = dp.query(0, e+1) + 1;
		if (a > dp.val(e)) {
			dp.update(e, a);
			res = max(res, a);
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		A[i] = -A[i];
	}
	int ans = LIS_leq(A);
	cout << ans << endl;
	return 0;
}