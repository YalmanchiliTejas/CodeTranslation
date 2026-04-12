/*input

*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <climits>
#include <random>

using namespace std; 

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
int GCD(int x,int y){return y?GCD(y,x%y):x;}
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,a,b) for(int i=(a);i<(b);i++)
#define repm(i,a,b) for(int i=(a);i>(b);i--)
#define rept(v) for(auto it=v.begin();it<v.end();it++)
#define all(v) v.begin(),v.end()
const int INF = 1<<30;
typedef long long ll;
typedef pair<int,int> pii;

int const MOD = 998244353;

struct seg {
	int l, r;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	ll n, x, m;
	cin >> n >> x >> m;
	x%=m;
	vector<int> v;
	set<int> seen;
	ll ans=0;
	rep(i, n) {
		if(seen.find(x)!=seen.end()) break;
		ans+=x;
		seen.insert(x);
		v.push_back(x);
		x=(x*x)%m;
	}
	vector<ll> cyc;
	repm(i, v.size()-1, -1) {
		if(v[i]==x) {
			cyc.push_back(v[i]);
			break;
		}
		cyc.push_back(v[i]);
	}
	reverse(all(cyc));
	vector<ll> pre;
	pre.push_back(cyc[0]);
	repl(i, 1, cyc.size()) pre.push_back(pre.back()+cyc[i]);
	ll left = n-v.size();
	ans+=(left/pre.size())*pre.back();
	if(left%pre.size()) ans+=pre[left%pre.size()-1];
	cout << ans;
	return 0;	
}
// 787 788 789 790 791 792