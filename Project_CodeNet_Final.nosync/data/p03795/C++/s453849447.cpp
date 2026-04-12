#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<functional>
#include<numeric>
#include<sstream>
#include<math.h>
#include <iomanip>
#define ll long long
#define PLL pair<ll,ll>
#define VS vector<string>
#define VL vector<ll>
#define VB vector<bool>
#define VPLL vector<pair<ll,ll> >
#define VVL vector<vector<ll> >
#define VVB vector<vector<bool> >
#define rep(i,a) for (ll i=0;i<a;i++)
#define nrep(i,n,a) for (ll i=n;i<a;i++)
#define mrep(i,a) for(ll i=a;i>=0;i--)
#define INF 1145141919810
#define PI 3.141592653589793238
#define VMIN(vec) *std::max_element(vec.begin(),vec.end())
#define VMIN(vec) *std::max_element(vec.begin(),vec.end())
#define VSUM(vec) std::accumulate(vec.begin(),vec.end(),0LL)
#define LTS(n) to_string(n)
#define STL(str) stoll(str)

using namespace std;

int main() {
	ll n;
	cin >> n;
	cout << 800 * n - (n / 15)*200 << endl;
	return 0;
}

