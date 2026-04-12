#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int a[50];
	int n, l, r;
	
	while (cin >> n >> l >> r, n) {
		rep(i, n)cin >> a[i];

		int ans = 0;
		for (int x = l; x <= r;x++) {
			int idx = -1;
			rep(i, n) {
				if (x%a[i]==0) {
					idx = i;
					break;
				}
			}

			if (idx!=-1) {
				if (idx % 2 == 0)ans++;
			}
			else if (n%2==0) {
				ans++;
			}

		}
		cout << ans << endl;

	}



	return 0;
}
