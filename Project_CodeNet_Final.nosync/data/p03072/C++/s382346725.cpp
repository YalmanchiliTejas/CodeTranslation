#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define MOD 1000000007
typedef pair<li, li> PI;

li h[111];

int main(void)
{
	li n;
	cin >> n;
	li res = 0;
	li ma = 0;
	rep(i, n) {
		cin >> h[i];
		if (ma <= h[i]) {
			res++;
		}
		ma = max(ma, h[i]);
	}
	cout << res << endl;



	return 0;
}