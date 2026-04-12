#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
#include <vector>
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
#define umin( x , y ) x = min( x , (y) )
#define ort (b+s)/2
#define y2 asrwjaelkf
#define y1 asseopirwjaelkf
#define set multiset
 
using namespace std;
 
typedef long long Lint;
typedef pair<Lint,Lint> ii;
typedef pair<int,char> ic;
typedef pair<ii,int> iii;
typedef pair<ii,ii> i4;
 
const int maxn = 1020;
const int maxm = 10000020;
const int MOd = 998244353;

int a;
string s, s2;

void solve() {
	scanf("%d",&a);
	Lint ans = 0, tot = 0;
	for(int i=0,j;i<a;i++) {
		scanf("%d",&j);
		ans += tot*j;
		tot += j;
		tot %= (1000000000+7);
		ans %= (1000000000+7);
	}
	cout << ans << endl;
}
 
int main() {
	int n = 1;
	// scanf("%d",&n);
	while( n-- ) solve();
 
	return 0;
}