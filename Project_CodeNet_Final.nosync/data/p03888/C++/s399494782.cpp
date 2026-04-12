#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
int main() {
	double a, b;
	cin >> a >> b;
	double ans = (a*b) / (a + b);
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}
