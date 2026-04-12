#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0;i < n;i++)cin >> a[i];

	sort(a.begin(),a.end(),greater<ll>());

	ll ans = 0;
	if(n % 2 == 1){
		//両端を小さくする場合
		ll sum = 0;
		for(int i = 1;i <= n;i++){
			if(i <= n / 2)sum += 2 * a[i-1];
			else{
				if(i <= n / 2 + 2)sum -= a[i-1];
				else sum -= 2 * a[i-1];
			}
		}
		ans = sum;
		sum = 0;
		//両端を大きくする場合
		for(int i = 1;i <= n;i++){
			if(i <= n / 2 - 1)sum += 2 * a[i-1];
			else if(i <= n / 2 + 1)sum += a[i-1];
			else sum -= 2 * a[i-1];
		}
		ans = max(ans,sum);
	}
	else{
		ll sum = 0;
		for(int i = 1;i <= n;i++){
			if(i < n / 2)sum += 2 * a[i-1];
			else if(i == n / 2)sum += a[i-1];
			else if(i == n / 2 + 1)sum -= a[i-1];
			else sum -= 2 * a[i-1];
		}
		ans = sum;
	}
	cout << ans << endl;
}
