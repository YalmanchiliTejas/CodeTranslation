#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N;
	cin >> N;
	int	A;
	vector<int>	tail_vec(N, -1);
	auto	comp = greater<int>();
	for (int i = 0; i < N; ++i) {
		cin >> A;
		*upper_bound(tail_vec.begin(), tail_vec.end(), A, comp) = A;
	}
	auto	end = lower_bound(tail_vec.begin(), tail_vec.end(), -1, comp);
	cout << end - tail_vec.begin() << endl;
}
