#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

struct SparseTable {
	vector<ll>A, log_table;
	vector<vector<int>> tableA;
	int N;

	SparseTable(vector<ll>A_) {
		N = A_.size();
		A.resize(N);
		for (int i = 0; i < N; i++)A[i] = A_[i];

		//対数計算は先にやっておく
		log_table.resize(N+1);
		for (int i = 2; i <= N; i++) {
			log_table[i] = log_table[i >> 1] + 1;
		}

		tableA.resize(N);
		for (int i = 0; i < N; i++) {
			tableA[i].resize(log_table[N] + 1);
		}

		//区間[i,i]
		for (int i = 0; i < N; i++) {
			tableA[i][0] = i;
		}
	}

	void push(int k, ll a) {
		A[k] = a;
	}

	//最大値のインデックスを持つテーブルを作る
	void maxtable() {
		//区間[i,i+2^k)の計算
		for (int k = 1; (1 << k) <= N; k++) {
			for (int i = 0; i + (1 << k) <= N; i++) {
				//区間[i,i+2^(k-1))と区間[i+2^(k-1),i+2^k)の最小値、最大値のインデックス
				int firstA = tableA[i][k - 1];
				int secondA = tableA[i + (1 << (k - 1))][k - 1];

				//最後に出てきた最大値
				if (A[firstA] > A[secondA]) {
					tableA[i][k] = firstA;
				}
				else {
					tableA[i][k] = secondA;
				}
			}
		}
	}

	//区間[s,t]内の最大値のインデックスを返す
	int maxquery(int s, int t) {
		int d = t - s + 1;
		int k = log_table[d];

		int index = 0;

		//区間[s,t]は区間[s,s+2^k)と[t-2^k+1,t)でカバーできる
		if (A[tableA[s][k]] > A[tableA[t - (1 << k) + 1][k]]) {
			index = tableA[s][k];
		}
		else {
			index = tableA[t - (1 << k) + 1][k];
		}

		return index;
	}

	//最小値のインデックスを持つテーブルを作る
	void mintable() {
		//区間[i,i+2^k)の計算
		for (int k = 1; (1 << k) <= N; k++) {
			for (int i = 0; i + (1 << k) <= N; i++) {
				//区間[i,i+2^(k-1))と区間[i+2^(k-1),i+2^k)の最小値、最大値のインデックス
				int firstA = tableA[i][k - 1];
				int secondA = tableA[i + (1 << (k - 1))][k - 1];

				//最後に出てきた最小値
				if (A[firstA] < A[secondA]) {
					tableA[i][k] = firstA;
				}
				else {
					tableA[i][k] = secondA;
				}
			}
		}
	}

	//区間[s,t]内の最小値のインデックスを返す
	int minquery(int s, int t) {
		int d = t - s + 1;
		int k = log_table[d];

		int index = 0;

		//区間[s,t]は区間[s,s+2^k)と[t-2^k+1,t)でカバーできる
		if (A[tableA[s][k]] < A[tableA[t - (1 << k) + 1][k]]) {
			index = tableA[s][k];
		}
		else {
			index = tableA[t - (1 << k) + 1][k];
		}

		return index;
	}
};



int main()
{
	int N; cin >> N;
	vector<ll>a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	SparseTable st(a);

	ll cnt = 0;
	while (1) {
		st.maxtable();
		int index = st.maxquery(0,N-1);

		if (st.A[index] < N)break;

		ll x = st.A[index] / N;
		ll y = st.A[index] % N;

		st.A[index] = y;
		for (int i = 0; i < N; i++) {
			if (i == index)continue;

			st.A[i] += x;
		}

		cnt+=x;
	}

	cout << cnt << endl;

    return 0;
}

