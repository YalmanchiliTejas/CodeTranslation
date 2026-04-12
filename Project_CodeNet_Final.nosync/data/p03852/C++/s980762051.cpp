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
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
typedef long long int ll;
const int INF = 1 << 30;
using namespace std;
#define pp pair<int,int>
#define FOR(i,a,n) for(int i=(ll)a;i<(ll)n;++i)
#define TFOR(i,n)FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
int main() {
	char c; cin >> c;
	cout << (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ? "vowel" : "consonant") << endl;
	return 0;
}