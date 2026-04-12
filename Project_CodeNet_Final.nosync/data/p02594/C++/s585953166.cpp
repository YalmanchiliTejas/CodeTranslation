#ifdef MY_LOCAL
#define MY_NAMESPACE(ns) namespace ns {
#define MY_NAMESPACE_    }
#define MY_DEBUG(s)      s
#else
#define MY_NAMESPACE(ns) 
#define MY_NAMESPACE_    
#define MY_DEBUG(s)      
#endif

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define EPS (1e-7)
#define IINF ((int)1e9)


MY_NAMESPACE(testbed)
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int x;
	cin >> x;

	if (x >= 30)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
	return 0;
}
MY_NAMESPACE_