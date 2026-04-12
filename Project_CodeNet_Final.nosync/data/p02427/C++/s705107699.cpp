#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int	N;
	cin >> N;
	rep(i, 1 << N)
	{
		cout << i << ':';
		rep(j, N)
		{
			if (i & (1 << j))	
				cout << ' ' << j;
		}
		cout << endl;
	}
}

