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
#define rep(i,n) for(ll i=0;i<(n);i++)
int main() {
	ll n, a[200020], b[200020];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	ll mia = a[n / 2 - 1], mib = a[n / 2];
	for (int i = 0; i < n; i++) {
		if (b[i] <= mia)cout << mib << endl;
		else cout << mia << endl;
	}
	return 0;
}