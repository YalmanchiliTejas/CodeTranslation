#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<climits>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll> lltpl;



/******************************************************************************************/


const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;



template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
	for (auto& e : t) fill_v(e, v);
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());

	ll ans = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2 - 1; i++) {
			ans += 2 * a[i];
		}
		ans += a[n / 2 - 1];
		ans -= a[n / 2];
		for (int i = n / 2 + 1; i < n; i++) {
			ans -= 2 * a[i];
		}

	}
	else {
		
		ll cnt1 = 0;
		for (int i = 0; i < n / 2 - 1; i++) {
			cnt1 += 2 * a[i];
		}
		cnt1 += a[n / 2 - 1] + a[n / 2];
		for (int i = n / 2 + 1; i < n; i++) {
			cnt1 -= 2 * a[i];
		}

		ll cnt2 = 0;
		for (int i = 0; i < n / 2; i++) {
			cnt2 += 2 * a[i];
		}
		cnt2 -= (a[n / 2] + a[n / 2 + 1]);
		for (int i = n / 2 + 2; i < n; i++) {
			cnt2 -= 2 * a[i];
		}
		ans = max(cnt1, cnt2);
	}
	cout << ans << endl;


}
