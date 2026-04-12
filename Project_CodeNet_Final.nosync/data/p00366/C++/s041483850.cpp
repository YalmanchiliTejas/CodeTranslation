#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>


using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

#define ARRAY_MAX 100005

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

//約数の列挙
template<typename T>
vector<T> divisor(T n) {
	vector<T> res;
	for (T i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i != n / i) {
				res.push_back(n / i);
			}
		}
	}
	return res;
}

int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}

	vector<int> div = divisor(maxi);

	sort(div.begin(), div.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto itr = lower_bound(div.begin(), div.end(), a[i]);
		ans += (*itr - a[i]);
	}
	cout << ans << endl;
}
