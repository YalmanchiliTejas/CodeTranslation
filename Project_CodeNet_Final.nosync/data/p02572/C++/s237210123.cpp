#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <array>
#include <memory>

#define IN(a,b) (a.find(b) != a.end())
#define p(a,b) make_pair(a,b)
#define readVec(a) for (int64_t __i = 0; __i<(int64_t)a.size();__i++){cin>>a[__i];}

// jimjam

template<typename T>
void pMin(T &a, T b) {if (b<a){a=b;}}
template<typename T>
void pMax(T &a, T b) {if (b>a){a=b;}}
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c);
template<typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A,B>& c) {std::cout << "(" << c.first << ", " << c.second << ")";return os;}

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int64_t mod = 1e9+7;
	int64_t n; cin >> n;
	vector<int64_t> a(n);
	readVec(a);
	
	int64_t ans=0;
	
	int64_t sumBefore=a[0];
	for (int i = 1; i < n; i++) {
		ans += a[i] * sumBefore;
		ans %= mod;
		sumBefore %= mod;
		sumBefore+=a[i];
	}
	cout << ans << endl;
	return 0;
}


