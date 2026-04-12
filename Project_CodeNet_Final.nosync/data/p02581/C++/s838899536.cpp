#include<vector>
#include<iostream>
#include<set>
#include<list>
#include<string>
#include<math.h>
#include<algorithm>
#include<unordered_set>


using namespace std;

int ctoi(char c) {

	switch (c)
	{
	case'0':
		return 0;
	case'1':
		return 1;
	case'2':
		return 2;
	case'3':
		return 3;
	case'4':
		return 4;
	case'5':
		return 5;
	case'6':
		return 6;
	case'7':
		return 7;
	case'8':
		return 8;
	case'9':
		return 9;
	default:
		cout << "ERR_ctoi" << endl;
		return -1;
	};
}
using ull = unsigned long long;
using ll = long long;


int index(int a, int b) {
	int M = max(a, b);
	int m = min(a, b);
	M++;
	m++;
	return M * (M - 1) / 2 + m - 1;
}


vector<int> dp;
vector<int> A;
vector<int> r;

void update(int k1, int k2, int v) {
	if (dp[index(k1, k2)] < v) {
		dp[index(k1, k2)] = v;

		r[k1] = max(r[k1], v);
		r[k2] = max(r[k2], v);
	}
}

int getmax(int k) {
	return r[k];
}

int main() {
	int N;
	cin >> N;
	A.resize(3 * N);
	for (int i = 0; i < 3 * N; ++i) {
		cin >> A[i];
		A[i]--;
	}

	dp.resize(N * (N + 1) / 2);
	for (int& i : dp) i = -1000000;

	dp[index(A[0], A[1])] = 0;

	r.resize(N);
	for (int i = 0; i < N; ++i) {
		r[i] = -1000000;
	}

	r[A[0]] = 0;
	r[A[1]] = 0;

	int combo3 = 0;
	for (int i = 0; i < N - 1; ++i) {
		int ind = 2 + 3 * i;

		if (A[ind] == A[ind + 1] && A[ind + 1] == A[ind + 2]) {
			combo3++;
			continue;
		}

		int a, b, c;
		c = -1;
		if (A[ind] == A[ind + 1]) {
			a = A[ind];
			b = A[ind + 2];
		}
		else if (A[ind + 1] == A[ind + 2]) {
			a = A[ind+1];
			b = A[ind];
		}
		else if (A[ind + 2] == A[ind]) {
			a = A[ind];
			b = A[ind + 1];
		}
		else {
			a = A[ind];
			b = A[ind + 1];
			c = A[ind + 2];
		}

		if (c != -1) {
			int allmax = -10000000;
			vector<int> pmax(N);
			for (int p = 0; p < N; ++p) {
				pmax[p] = getmax(p);
				allmax = max(allmax, pmax[p]);
			}
			
			int aa = dp[index(a, a)];
			int bb = dp[index(b, b)];
			int cc = dp[index(c, c)];

			for (int p = 0; p < N; ++p) {
				update(p, a, pmax[p]);
				update(p, b, pmax[p]);
				update(p, c, pmax[p]);
			}

			update(b, c, 1 + aa);
			update(a, c, 1 + bb);
			update(b, a, 1 + cc);
			update(b, c, allmax);
			update(a, c, allmax);
			update(b, a, allmax);
		}
		else {
			int allmax = -10000000;
			vector<int> pmax(N);
			vector<int> aline(N);
			for (int p = 0; p < N; ++p) {
				pmax[p] = getmax(p);
				aline[p] = dp[index(a, p)];
				allmax = max(allmax, pmax[p]);
			}

			int aa = dp[index(a, a)];
			int bb = dp[index(b, b)];

			for (int p = 0; p < N; ++p) {
				update(p, a, pmax[p]);
				update(p, b, pmax[p]);
				update(p, b, 1 + aline[p]);
			}

			update(a, a, allmax);
			update(a, b, allmax);
			update(a, a, bb + 1);
			update(a, b, aa + 1);
		}
	}

	update(A.back(), A.back(), dp[index(A.back(), A.back())] + 1);

	int res = 0;

	for (int i = 0; i < N; ++i) {
		res = max(r[i],res);
	}

	cout << res + combo3 << endl;
	return 0;
}
