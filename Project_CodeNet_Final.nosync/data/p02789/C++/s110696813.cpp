#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <iterator>
#include <functional>
#include <numeric>
#include <cmath>
#include <stack>
#include <limits>
#include <ctime>

using namespace std;

#define ll long long
#define f0(i,n)for(ll i=0;i<n;i++)
#define f0r(i,n)for(ll i=n-1;i>=0;i--)
#define fc(i,c,n,s)for(ll i=c;i<=n;i+=s)
#define fcr(i,c,n,s)for(ll i=n;i>=c;i-=s)
#define sc(n) static_cast<ll>(n)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef list<ll> LST;
typedef vector<ll> VEC;
typedef map<ll, ll> MAP;

int main() {
	IO;
#ifdef _DEBUG
	ifstream cin("In.txt");
#endif
	ll n,m;
	cin >> n >> m;
	cout << (m < n ? "No":"Yes") << endl;
	return 0;
}