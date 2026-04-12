# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
# include <random>
# include <chrono>
# include <cstdlib>
# include <tuple>
# include <array>
# include <climits>
#define ll long long int
#define rep(i,rept) for (ll i = 0; i < rept; i++)
#define yes(b) std::cout<< (b ? "Yes" : "No")
#define YES(b) std::cout<< (b ? "YES" : "NO")
using namespace std;
/*int ketawa(ll num) {
	int dig, sum = 0;
	while (num) {
		dig = num % 10;
		sum = sum + dig;
		num = num / 10;
	}
	return sum;
}
*/
ll func(ll a, ll b, ll c, ll d,int n) {
	return ((c / (d - b) + n)*(d - b)) + (a % (d - b));
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s="aoieu";
	char c;
	cin >> c;
	cout << (s.find(c) == string::npos ? "consonant" : "vowel");
	return 0;
}
