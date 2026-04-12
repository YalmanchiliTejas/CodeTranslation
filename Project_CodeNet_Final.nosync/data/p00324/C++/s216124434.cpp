
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>
#include<iomanip>
#include<iterator>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,n) for(int i=a; i<n; i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, char> plc;

int N;
ll cum_sum[200010];
int ans;
map<ll, int> m;

int main()
{	
	cin >> N;
	rep(i, N) {
		int d; cin >> d;
		cum_sum[i + 1] = cum_sum[i] + d;
		
	}

	for (int i = 0; i <= N; i++) {
		if (!m[cum_sum[i]])m[cum_sum[i]] = i+1;
		else {
			ans = max(ans, i+1 - m[cum_sum[i]]);
			m[cum_sum[i]] = min(m[cum_sum[i]], i+1);
		}
	}
	cout << ans << endl;
	return 0;
}