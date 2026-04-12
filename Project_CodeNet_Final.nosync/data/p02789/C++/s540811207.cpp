#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>
#include <queue>
#include <cctype>
#include <stack>
#include <random>
#include <list>
#include <numeric>
#include <chrono>
#include <set>


#define rep(i,p,q) for(ll i = p;i < q;i++)
#define ll long long

using namespace std;

vector<vector<ll>> graph;
vector<ll> query;
vector<ll> ans;
vector<ll> visited;


const long long MAX_N = 1 << 17;
const long long MOD = 1000000007;

long long dat[2 * MAX_N - 1];

ll fact(ll n) {
	if (n == 1) return 1;
	if (n == 0) return 0;
	return n * fact(n - 1);
}

ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

//ABC152
int main(void) {
	ll n, m;
	cin >> n >> m;
	cout << (n == m ? "Yes" : "No") << endl;
}
