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
#include<deque>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1000000;
const int mod = 998244353;
const ll INF = 1LL << 60;
#define rep(i,n) for(ll i=(ll)0;i<(ll)n;++i)
#define ALL(x) x.begin(),x.end()
#define pp pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define fix(n) fixed<<setprecision(n)
#define itr vector<ll>::iterator
int main() {
	char c;
	cin >> c;
	cout << ((c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') ? "vowel" : "consonant") << endl;
	return 0;
}