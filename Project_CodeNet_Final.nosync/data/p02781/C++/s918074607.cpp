#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define Inf 1000000000
#define nmax_def 110000
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

ll nCm_array[1000][1000]; // nCm_array[6][2]  = 6C2,  nCm_array[9][9] = 9C9
void nCm(void)
{
	ll i, j;
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j <= i; j++)
		{
			ll ans;
			if ((j == 0) || (j == i))
				ans = 1;
			else
				ans = nCm_array[i - 1][j] + nCm_array[i - 1][j - 1];
			nCm_array[i][j] = ans;
		}
	}
}

int main() {
	nCm();
	string N;
	cin >> N;
	int K;
	cin >> K;
	int Nlen = N.length();
	ll ans = 0;
	ll aa = 0;
	rep(i, Nlen) {
		if (N[i] != '0')
			aa++;
	}
	if (aa == K)
		ans++;
	int deccount = 0;
	rep(i, Nlen) {
		int n = (int)N[i] - (int)'0';
		rep(j, n) {
			if (j == 0) {
				if (K - deccount >= 0) {
					ll anstmp = nCm_array[Nlen - i - 1][K - deccount];
					rep(l, K - deccount)
						anstmp *= 9LL;
					ans += anstmp;
				}
			}
			else {
				if (K - deccount - 1 >= 0) {
					ll anstmp = nCm_array[Nlen - i - 1][K - deccount - 1];
					rep(l, K - deccount - 1)
						anstmp *= 9LL;
					ans += anstmp;
				}
			}
		}
		if (n != 0)
			deccount++;
	}
	cout << ans << endl;

	return 0;
}