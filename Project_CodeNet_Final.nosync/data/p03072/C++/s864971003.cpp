#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stdbool.h>
#include<math.h>
#include<sstream>
#include<math.h>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
#include<bitset>
typedef long long ll;
#define N (1000000000+7)
#define INF 1e10
using namespace std;
typedef pair<ll, ll> P;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main(void){
	int n;
	cin >> n;
	vector<int>h(n);
	for (int i = 0;i < n;i++)cin >> h[i];
	int ans = 1;
	for (int i = 1;i < n;i++) {
		bool can = true;
		for (int j = 0;j <= i - 1;j++) {
			if (h[j] > h[i]) {
				can = false;
				break;
			}
		}
		if (can)ans++;
	}
	cout << ans << endl;
	return 0;
}