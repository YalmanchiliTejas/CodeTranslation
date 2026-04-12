#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

std::vector<std::vector<bool> > solve(std::vector<int> a, std::vector<int> b) {
	// -1 : no restriction
	// 0 : always 0
	// 1 : at least 1 0s
	// 2 : at least 1 1s
	// 3 : always 1
	int n = a.size();
	if (n == 1) {
		if (a[0] == 1) a[0] = 0;
		if (a[0] == 2) a[0] = 3;
		if (a[0] != (b[0] == 2 || b[0] == 3)) return {};
		return { { (bool) a[0] } };
	}
	std::vector<std::vector<bool> > res(n, std::vector<bool> (n));
	if (std::count(a.begin(), a.end(), 0) && std::count(b.begin(), b.end(), 3)) return {};
	if (std::count(a.begin(), a.end(), 3) && std::count(b.begin(), b.end(), 0)) return {};
	if (std::count(a.begin(), a.end(), 0)) for (auto &i : b) if (i == 1) i = -1;
	if (std::count(a.begin(), a.end(), 3)) for (auto &i : b) if (i == 2) i = -1;
	if (std::count(b.begin(), b.end(), 0)) for (auto &i : a) if (i == 1) i = -1;
	if (std::count(b.begin(), b.end(), 3)) for (auto &i : a) if (i == 2) i = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 3) for (int j = 0; j < n; j++) res[i][j] = 1;
		if (b[i] == 3) for (int j = 0; j < n; j++) res[j][i] = 1;
	}
	if (std::count(a.begin(), a.end(), 0) == n) {
		for (auto &j : b) if (j >= 2) return {};
		return res;
	} else if (std::count(a.begin(), a.end(), 3) == n) {
		for (auto &j : b) if (j == 0 || j == 1) return {};
		return res;
	} else if (std::count(b.begin(), b.end(), 0) == n) {
		for (auto &j : a) if (j >= 2) return {};
		return res;
	} else if (std::count(b.begin(), b.end(), 3) == n) {
		for (auto &j : a) if (j == 0 || j == 1) return {};
		return res;
	}
	auto r0 = std::find(a.begin(), a.end(), -1) - a.begin();
	if (r0 != n) {
		for (int i = 0; i < n; i++) if (b[i] == 1 || b[i] == 2) res[r0][i] = b[i] == 2;
		for (int i = 0; i < n; i++) if (a[i] == 1 || a[i] == 2)
			for (int j = 0; j < n; j++) if (b[j] && b[j] != 3) res[i][j] = a[i] == 2;
		return res;
	}
	auto r1 = std::find(b.begin(), b.end(), -1) - b.begin();
	if (r1 != n) {
		for (int i = 0; i < n; i++) if (a[i] == 1 || a[i] == 2) res[i][r1] = a[i] == 2;
		for (int i = 0; i < n; i++) if (b[i] == 1 || b[i] == 2)
			for (int j = 0; j < n; j++) if (a[j] && a[j] != 3) res[j][i] = b[i] == 2;
		return res;
	}
	std::vector<int> rows, columns;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1 || a[i] == 2) rows.push_back(i);
		if (b[i] == 1 || b[i] == 2) columns.push_back(i);
	}
	if (rows.size() == 1) {
		bool ok = false;
		for (int j = 0; j < (int) columns.size(); j++) {
			res[rows[0]][columns[j]] = b[columns[j]] == 2;
			if (b[columns[j]] == a[rows[0]]) ok = true;
		}
		if (ok) return res;
		else return {};
	}
	if (columns.size() == 1) {
		bool ok = false;
		for (int j = 0; j < (int) rows.size(); j++) {
			res[rows[j]][columns[0]] = a[rows[j]] == 2;
			if (b[columns[0]] == a[rows[j]]) ok = true;
		}
		if (ok) return res;
		else return {};
	}
	for (int i = 0; i < std::max<int>(columns.size(), rows.size()); i++) res[rows[i % rows.size()]][columns[i % columns.size()]] = true;
	return res;
}

void random_test() {
	std::random_device rnd_dev;
	std::mt19937 rnd(rnd_dev() ^ clock());
	int n = 5;
	for (int i = 0; i < 1 << (2 * n); i++) {
		for (int j = 0; j < 1 << (2 * n); j++) {
			std::vector<int> a(n);
			std::vector<int> b(n);
			for (int k = 0; k < n; k++) {
				a[k] = i >> (2 * k) & 3;
				b[k] = j >> (2 * k) & 3;
			}
			auto tmp = solve(a, b);
			if (!tmp.size()) continue;
			auto fail = [&] () {
				std::cerr << "FAILED" << std::endl;
				for (auto i : a) std::cerr << i << " ";
				std::cerr << std::endl;
				for (auto i : b) std::cerr << i << " ";
				std::cerr << std::endl;
				for (auto &k : tmp) {
					for (auto l : k) std::cerr << l << " ";
					std::cerr << std::endl;
				}
				exit(1);
			};
			for (int k = 0; k < n; k++) {
				if (a[k] == 0 && std::count(tmp[k].begin(), tmp[k].end(), 1)) fail();
				if (a[k] == 1 && std::count(tmp[k].begin(), tmp[k].end(), 1) == n) fail();
				if (a[k] == 2 && std::count(tmp[k].begin(), tmp[k].end(), 0) == n) fail();
				if (a[k] == 3 && std::count(tmp[k].begin(), tmp[k].end(), 0)) fail();
			}
			for (int k = 0; k < n; k++) for (int l = 0; l < k; l++) std::swap(tmp[k][l], tmp[l][k]);
			for (int k = 0; k < n; k++) {
				if (b[k] == 0 && std::count(tmp[k].begin(), tmp[k].end(), 1)) fail();
				if (b[k] == 1 && std::count(tmp[k].begin(), tmp[k].end(), 1) == n) fail();
				if (b[k] == 2 && std::count(tmp[k].begin(), tmp[k].end(), 0) == n) fail();
				if (b[k] == 3 && std::count(tmp[k].begin(), tmp[k].end(), 0)) fail();
			}
		}
	}
}
void test() {
	int n = ri();
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) a[i] = ri();
	for (int i = 0; i < n; i++) b[i] = ri();
	auto tmp = solve(a, b);
	for (auto &i : tmp) {
		for (auto j : i) std::cerr << j << " ";
		std::cerr << std::endl;
	}
}

int main() {
	// random_test();
	// test();
	int n = ri();
	int a[n], b[n];
	uint64_t c[n], d[n];
	for (auto &i : a) i = ri();
	for (auto &i : b) i = ri();
	for (auto &i : c) scanf("%" SCNu64, &i);
	for (auto &i : d) scanf("%" SCNu64, &i);
	
	uint64_t res[n][n];
	memset(res, 0, sizeof(res));
	for (int i = 0; i < 64; i++) {
		std::vector<int> x(n), y(n);
		for (int j = 0; j < n; j++) {
			x[j] = ((c[j] >> i & 1) ? 3 : 1) - a[j];
			y[j] = ((d[j] >> i & 1) ? 3 : 1) - b[j];
		}
		auto tmp = solve(x, y);
		if (!tmp.size()) {
			puts("-1");
			return 0;
		}
		for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) if (tmp[j][k]) res[j][k] |= 1ULL << i;
	}
	for (auto &i : res) {
		for (auto j : i) printf("%" PRIu64 " ", j);
		puts("");
	}
	return 0;
}
