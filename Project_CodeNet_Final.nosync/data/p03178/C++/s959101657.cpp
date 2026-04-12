#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <regex>
#include <stdexcept>
#include <unordered_set>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <time.h>
#include <numeric>
#include <complex>
 
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using D = double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
 
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define fill(x, y) memset(x, y, sizeof(x))
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define rep(i, x)  for(int i = 0; i < (x); i++)
#define rrep(i, x) for(int i = (x - 1); i >= 0; i--)
#define y1 y1_1234413
#define j1 j1_235
#define y0 y0_235
#define j0 j0_256
#define fi first
#define se second
#define itn int
#define re return
#define prev PREV
#define next NEXT
 
#define sz(x) ((int)x.size())
 
const int inf = 2e9;
const ld st = 0.000001;
const ld pi = acos((ld)-1);
 
#define FILENAME ""
 
const ll maxn = 2e5 + 50;
const int mod = 1000000007;
const int L = 10 * 1000 + 7;
const int S = 107;

void add_self (int& a, int b) {
 	a += b;
 	if (a >= mod) {
 	 	a -= mod;
 	}
}

int dp[L][S][2];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);                                                         
	int d;
	string s;
	cin >> s >> d;
	dp[0][0][0] = 1;
	for (int i = 0; i < sz(s); i++) {
	 	for (int j = 0; j < d; j++) {
	 		for (int k = 0; k < 2; k++) {
	 			int r = 9;
	 			if (k == 0) {
	 			 	r =  s[i] - '0';
	 			}
	 		 	for (int dig = 0; dig <= r; dig++) {
	 		 		int r1 = k;
	 		 	 	if (((s[i] - '0') > dig)) {
	 		 	 		r1 = 1; 	
	 		 	 	}
	 		 	 	add_self(dp[i + 1][(j + dig) % d][r1], dp[i][j][k]);
	 		 	}
	 		}
	   	}
	}
	int answer = (dp[sz(s)][0][0] + dp[sz(s)][0][1]) % mod;
	answer = (answer + mod - 1) % mod; 
	cout << answer;
   	return 0;
}
