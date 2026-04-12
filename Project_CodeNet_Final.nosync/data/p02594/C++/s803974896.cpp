#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <bitset>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define x  first
#define y  second
#define mp make_pair
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#ifndef ONLINE_JUDGE
	// #include "debug.h"
#else
// #define debug(...) 42
#endif

const int mxN=100;
const ld PI=acos(-1);
const int MD=1e9+7;

int main() {
	fast_cin();
	int t=1;
	// cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		if(x>=30) cout<<"Yes";
		else cout<<"No";
	}
	return 0;	
}