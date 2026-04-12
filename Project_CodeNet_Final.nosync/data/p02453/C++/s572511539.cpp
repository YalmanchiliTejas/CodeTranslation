#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int	N;
	cin >> N;
	vector<int> vec(N);
	rep(i, N)
		cin >> vec.at(i);
	int	Q;
	cin >> Q;
	rep(i, Q)
	{
		int	k;
		cin >> k;
		vector<int>::iterator it;
		it = partition_point(vec.begin(), vec.end(), [k](int element){return (element < k);});
		cout << distance(vec.begin(), it) << endl;
	}
}

