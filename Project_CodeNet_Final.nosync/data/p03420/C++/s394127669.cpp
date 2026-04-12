#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

int n, k;

void read()
{
	cin >> n >> k;
}

void solve()
{
	int64_t answer = 0;
	for(int b = 1; b <= n; b++)
	{
		int initial_h = b - 1;
		if(initial_h >= k) answer += initial_h - k + 1;
		if(k == 0) answer -= 1;

		for(int low = b; low <= n; low += b)
		{
			int high = low + b - 1;
			chkmin(high, n);
				
			int len = high - low;
			if(len >= k) answer += (len - k + 1);
		}
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

