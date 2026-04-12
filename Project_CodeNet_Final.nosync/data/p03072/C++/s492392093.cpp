#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <iomanip>
#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#define double long double
#define int long long
#define low lower_bound
#define upp upper_bound
#define mod 1000000007 //10^9+7
#define inf 10000000000000000 //10^16
#define rep(i,n) for(int i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define vsort(vec) sort(all(vec))
#define vrever(vec) reverse(all(vec));
#define vunsort(vec) vsort(vec); vrever(vec);
#define bisea binary_search
#define cend cout<<endl;
using namespace std;

signed main() {
	int n;
	cin >> n;
	int h[22];
	int cnt = 0;
	rep(i, n) cin >> h[i];
	rep(i, n) {
		bool can = true;
		rep(j, i) {
			if (!(h[j] <= h[i])) can = false;
		}
		if (can) cnt++;
	}
	cout << cnt << endl;
}