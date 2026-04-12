#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <map>
#include<cmath>
#include <queue>
#include <numeric>

using lli = long long int;
int inf = 1000000007;
using namespace std;

int N;

int main()
{
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];

	multiset<int> set;
	for (int i = 0; i < N; i++) {

		if (set.lower_bound(A[i]) != set.begin()) {
			auto num = prev(set.lower_bound(A[i]));
			set.erase(num);
		}
		set.insert(A[i]);
	}
	cout << set.size() << endl;
	return 0;
}