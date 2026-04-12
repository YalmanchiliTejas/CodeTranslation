#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <tuple>

#define rep(i,n) for(ll i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
//	std::cout<<std::fixed<<std::setprecision(10);

int main() {
	int n, m;
	cin >> n >> m;
	if(n==m) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

