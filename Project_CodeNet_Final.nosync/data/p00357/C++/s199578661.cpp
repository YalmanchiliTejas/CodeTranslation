
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
	
int n;
vector<int> d;

bool check() {
	int mx = 0;
	bool ans = true;
	rep(i, n) {
		mx = max(d[i]+i, mx);
		if (mx <= i)return false;
		if (mx >= n - 1)return true;
	}
	return false;
}

int main()
{
	cin >> n;
	d.resize(n);

	rep(i, n) {
		cin >> d[i];
		d[i] /= 10;
	}
	bool ans1 = check();
	reverse(d.begin(), d.end());
	bool ans2 = check();
	if (ans1 && ans2)cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}