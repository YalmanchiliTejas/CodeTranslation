#include <cstdio>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define INF 1000000000
#define mod 1000000007
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned int uii;
typedef pair<int,int> pii;
typedef pair<int, pair<int, int> >piii;
typedef unsigned long long uLL; 
typedef vector<int> vii; 
//__int128
const int maxn = 2e5;
int s[maxn];
std::vector<LL> d[maxn];

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

LL lcm(LL a, LL b){
	return a / gcd(a, b) * b;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	int n;
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; ++i){
		d[i].pb(0);
	}
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	for(LL c = 1; c < n; ++c){
		for(LL k = 1; n - 1 - k * c > c; ++k){
			d[c].pb(d[c][k - 1] + s[k * c] + s[n - 1 - k * c]);
		}
	}
	// cout << d[1][1] << endl;
	LL res = 0;
	for(LL c = 1; c < n; ++c){
		for(LL k = 0; k < (int)d[c].size(); ++k){
			LL a = n - 1 - k * c;
			// LL x = lcm(a, c);
			// if(x + a - c < n - 1) continue;
			if(a%c == 0 && a/c <= k) continue;
			// res = max(res, d[c][k]);
			if(res < d[c][k]){
				res = d[c][k];
				// printf("%d %d %d\n", c, k, d[c][k]);
			}
		}
	}
	cout << res << endl;
	return 0;
}