#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

void binarySearch(int num, deque<int> &dq) {
	int left = -1;
	int right = dq.size();
	int mid = (right + left) / 2;
	while (right - left > 1) {
		mid = (right + left) / 2;
		if (dq[mid] >= num)right = mid;
		else left = mid;
	}
	//cout << dq[left] << "->";
	dq[left] = num;
	//cout << num << endl;
}

int main() {
	int N; cin >> N;
	vector<int> maxes;
	deque<int> dq;
	int preNum = INF;
	rep(i, N) {
		int a; cin >> a;
		if (a <= preNum) {
			if (dq.empty() || dq.front() >= a) {
				dq.push_front(a);
				//cout << "push: " << a << endl;
			}
			else {
				binarySearch(a, dq);
				//cout << "concat: " << a << endl;
			}
		}
		else {
			binarySearch(a, dq);
			//cout << "concat: " << a << endl;
		}
		preNum = a;
	}
	cout << dq.size();
}
