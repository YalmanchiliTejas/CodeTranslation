#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	vector<ll>xdic;
	rep(i, 0, n)cin >> a[i];
		
	vector<ll>ans;
	rep(i, 0, n) {
		if (ans.size() == 0) {
			ans.pb(a[i]);
		}
		else {
			if (a[i] > ans.back()) {
				ans[ans.size()-1] = a[i];
			}
			else if (a[i] <= ans[0]) {
				ans.insert(ans.begin(),a[i]);
			}
			else {
				int ok = 0, ng = ans.size() - 1;
				while (ng - ok > 1) {
					int mid = (ng + ok) / 2;
					if (ans[mid] < a[i])ok = mid;
					else ng = mid;
				}
				ans[ok] = a[i];
			}
		}
	}
	puts(ans.size());

	return 0;
}
