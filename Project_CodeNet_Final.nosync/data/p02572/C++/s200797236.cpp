#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

const ll DENOMI = 1000000007LL;

int main()
{
	int n;
	cin >> n;
	auto a = vector<ll>(n + 1);
	auto s = vector<ll>(n + 1);
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
		s[i] = (a[i] + s[i - 1]) % DENOMI;
	}
	ll ans = 0LL;
	for(int i = 1; i < n + 1; ++i){
		ans = (ans + a[i] * s[i - 1] % DENOMI) % DENOMI;
	}
	cout << ans << endl;

	return 0;
}