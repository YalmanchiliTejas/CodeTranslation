#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
 
#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;
 
ll n, k, cnt;
 
int main() {
	cin >> n >> k;
	cnt = 0;
	if (k == 0) {
		cnt = n*n;
	}
	else
		for (int i = k + 1; i <= n; i++)
			cnt += (i - k)*(n / i) + max(ll(0), n%i - (k - 1));
	cout << cnt << endl;
	return 0;
}