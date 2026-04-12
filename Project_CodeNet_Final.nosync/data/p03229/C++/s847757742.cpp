#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll A[100010];

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A, A + N);
	ll sum1 = 0, sum2 = 0;
	{
		bool tail = true;
		ll l, r, il = 1, ir = N - 1, n = 1;
		auto& sum = sum1;
		l = r = A[0];
		//cerr << A[0] << " ";
		for (int i = 1; i < N; i += 2) {
			int idx1, idx2;
			if (tail) {
				idx1 = ir;
				idx2 = ir - 1;
				ir -= 2;
			}
			else {
				idx1 = il;
				idx2 = il + 1;
				il += 2;
			}
			sum += abs(l - A[idx1]);
			l = A[idx1];
			++n;
			//cerr << A[idx1] << " ";
			if (n < N) {
				sum += abs(r - A[idx2]);
				r = A[idx2];
				++n;
				//cerr << A[idx2] << " ";
			}
			tail = !tail;
		}
		//cerr << endl;
	}
	{
		bool tail = false;
		ll l, r, il = 0, ir = N - 2, n = 1;
		auto& sum = sum2;
		l = r = A[N-1];
		//cerr << A[N-1] << " ";
		for (int i = 1; i < N; i += 2) {
			int idx1, idx2;
			if (tail) {
				idx1 = ir;
				idx2 = ir - 1;
				ir -= 2;
			}
			else {
				idx1 = il;
				idx2 = il + 1;
				il += 2;
			}
			sum += abs(l - A[idx1]);
			l = A[idx1];
			++n;
			//cerr << A[idx1] << " ";
			if (n < N) {
				sum += abs(r - A[idx2]);
				r = A[idx2];
				++n;
				//cerr << A[idx2] << " ";
			}
			tail = !tail;
		}
		//cerr << endl;
	}
	ll sum = max(sum1, sum2);
	cout << sum << endl;
	return 0;
}