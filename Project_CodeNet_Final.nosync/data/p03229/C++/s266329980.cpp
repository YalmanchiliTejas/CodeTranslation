#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <limits>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	deque<int> B;
	{
		auto it = A.begin();
		auto itr = A.rbegin();
		rep(i, N) {
			if (i == 0) {
				B.push_back(*it++);
			} else {
				int d = (i + 1) / 2;
				if (d % 2 == 0) {
					if (i % 2 == 0)
						B.push_back(*it++);
					else
						B.push_front(*it++);
				} else {
					if (i % 2 == 0)
						B.push_back(*itr++);
					else
						B.push_front(*itr++);
				}
			}
		}
	}
	ll ans = 0;
	rep(i, N - 1) {
		ans += abs(B[i] - B[i + 1]);
	}
	{
		auto it = A.rbegin();
		auto itr = A.begin();
		//deque<int> B;
		B.clear();
		rep(i, N) {
			if (i == 0) {
				B.push_back(*it++);
			} else {
				int d = (i + 1) / 2;
				if (d % 2 == 0) {
					if (i % 2 == 0)
						B.push_back(*it++);
					else
						B.push_front(*it++);
				} else {
					if (i % 2 == 0)
						B.push_back(*itr++);
					else
						B.push_front(*itr++);
				}
			}
		}
		ll ans2 = 0;
		rep(i, N - 1) {
			ans2 += abs(B[i] - B[i + 1]);
		}
		ans = max(ans, ans2);
	}

	cout << ans << endl;
	return 0;
}
