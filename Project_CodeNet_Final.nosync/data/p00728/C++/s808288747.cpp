#include <iostream>
#include <cmath>
#include <utility>
#include <functional>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <stdlib.h>
using namespace std;
#define rep(i,n,x) for(int i=n;i<x;i++)
#define rem(i,n,x) for(int i=n;i>x;i--)
#define SORT(x) sort(x.begin(),x.end())
#define REV(x) reverse(x.begin(),x.end())
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define setp(x) setprecision(x)
using LL = long long;
using ULL = unsigned long long;

int main() {
	int n;
	cin >> n;

	while (n != 0) {
		vector<int> point(n);
		for (int i = 0; i < n; i++) cin >> point[i];

		sort(point.begin(), point.end());
		int sum = 0;
		for (int i = 1; i < n - 1; i++) sum += point[i];

		cout << sum / (n - 2) << endl;

		cin >> n;
	}

	return 0;
}
