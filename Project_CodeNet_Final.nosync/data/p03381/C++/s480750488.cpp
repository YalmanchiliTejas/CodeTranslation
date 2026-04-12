#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 10;
int n, m, ans, len;
int Arr[MAX_N];
int Brr[MAX_N];
int Fen[MAX_N];

void upd (int tmp, int val) {
	for (; tmp < MAX_N; tmp += tmp & -tmp)
		Fen[tmp] += val;
}

int get (int tmp) {
	int cnt = 0;
	int pointer = 0;
	for (int i = 20; ~i; i--)
		if ((pointer | (1 << i)) < MAX_N && cnt + Fen[pointer | (1 << i)] < tmp) {
			pointer |= (1 << i);
			cnt += Fen[pointer];
		}

	return pointer + 1;
}

int Map (int d) {
	return lower_bound(Brr, Brr + len, d) - Brr + 1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> Arr[i];
		Brr[i] = Arr[i];
	}
	
	sort(Brr, Brr + n);
	len = unique(Brr, Brr + n) - Brr;

	for (int i = 0; i < n; i++)
		upd(Map(Arr[i]), +1);

	for (int i = 0; i < n; i++) {
		upd(Map(Arr[i]), -1);
		cout << Brr[get(n / 2) - 1] << "\n";

		upd(Map(Arr[i]), +1);
	}
	return 0;
}