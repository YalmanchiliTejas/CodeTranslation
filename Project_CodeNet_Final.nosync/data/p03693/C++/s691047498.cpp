#include	<bits/stdc++.h>
using	namespace	std;

// int/long:		-2147483648 - 2147483648 (-2^31 <= int < 2^31)
// long/long long:	-9223372036854775808 - 9223372036854775807 (-2^63 <= long < 2^63)

#define	INF (1<<29)
//536870912

// lower_bound(A.begin(), A.end(), N)
// upper_bound(...

// bit: &/and, |/or, ^/xor, ~/not

#define	MOD 1000000007

int	main() {
	int r, g, b;
	cin >>r >>g >>b;
	b +=g*10;
	if (0==b%4)
		cout <<"YES" <<endl;
	else
		cout <<"NO" <<endl;
	return 0;
}

