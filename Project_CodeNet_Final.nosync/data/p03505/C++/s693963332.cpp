#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long K, A, B;
	cin >> K >> A >> B;

	long long ans = 0;
	if( A >= K ) ans = 1;
	else if( A <= B ) ans = -1;
	else {
		long long d = A - B;
		ans = (K - A + d - 1) / d * 2 + 1;
	}

	cout << ans << endl;
}
