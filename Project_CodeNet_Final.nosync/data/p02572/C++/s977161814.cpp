#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <bitset>

#define _GLIBCXX_DEBUG
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define p_b push_back
#define e_b emplace_back
#define m_p make_pair
#define m_t make_tuple

using namespace std;

int main() {
	ll md = 1000000007, ans = 0, sum=0;
	int n;
	cin >> n;
	vector<ll> vec(n);

	rep(i, n) {
		cin >> vec[i];
		sum += vec[i];
		sum %= md;
	}

	rep(i, n) {
		sum -= vec[i];
		if (sum < 0) sum += md;
		ans += vec[i] * sum;
		ans %= md;
	}

	cout << ans << endl;

}