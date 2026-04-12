# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<random>
#include<deque>
#include<cstdio>
#include<fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2000100;
const int mod = (int)pow(10, 9) + 7;
const ll INF = 1LL << 60;
#define rep(i,n) for(ll i=(ll)0;i<(ll)n;++i)
#define ALL(x) x.begin(),x.end()
#define pp pair<ll,ll>
#define ppp pair<pp,ll>
#define fi first
#define se second
#define pb push_back
#define fix(n) fixed<<setprecision(n)
#define itr vector<ll>::iterator
#define print(s) cout<<s<<endl
#define inp(s) cin>>s
string yn(bool b) { return (b ? "Yes" : "No"); }
string YN(bool b) { return (b ? "YES" : "NO"); }
ll n, a[300010];
bool ans=1;
int main(){
	cin >> n;
	ll r = 0;
	rep(i, n) {
		cin >> a[i], a[i] /= 10;
		if (i <= r && i + a[i] > r)r = min(i + a[i],n-1);
	}
	if (r != n - 1)ans = 0;
	reverse(a, a + n);
	r = 0;
	rep(i, n) {
		if (i <= r && i + a[i] > r)r = min(n-1,i + a[i]);
	}
	if (r != n - 1)ans = 0;
	cout << (ans ? "yes" : "no") << endl;
	return 0;
}
