//Jai Shree Ram
//#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define loopi(stop) for(int i=0; i<stop; i++)
#define loopj(stop2) for(int j=0; j<stop2; j++)
#define loopk(stop3) for(int k=0; k<stop3; k++)
#define loopi1(stop) for(int i=1; i<=stop; i++)
#define loopj1(stop2) for(int j=1; j<=stop2; j++)
#define loopk1(stop3) for(int k=1; k<=stop3; k++)
#define loopse(kt,sstart, eend) for(int kt = sstart; kt<eend; kt++)
#define faster_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define file_io_cf freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define p_b push_back
#define pii pair<int,int>
#define fi first
#define se second
#define prec_10 << fixed << setprecision(10)
#define DEB cout<<"DEBUG"<<'\n';
#define SRAND srand(time(0));

using namespace std;

int mod = 1000000007;

template <typename T>
void O(T x) {
	cout << x << '\n';
}

///////////////////////////////////CODE STARTS HERE///////////////////////////////////////////

int32_t main() {

	faster_io
	// file_io_cf

	int n; cin >> n;
	int a[n];
	loopi(n) {
		cin >> a[i];
	}

	int sum = 0;

	int ans = 0;

	loopi(n) {
		if (i > 0) {
			ans += (sum * a[i])%mod;
			ans = ans % mod;

		}
		sum += a[i];
		sum = sum % mod;
	}

	O(ans);


	return 0;
}