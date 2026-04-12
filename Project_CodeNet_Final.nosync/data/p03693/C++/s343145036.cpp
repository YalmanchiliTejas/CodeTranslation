#include <iostream>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mp make_pair
#define fname ""
#define fi first
#define se second
#define sz(a) (int)a.size()
#define pb push_back
#define fo(i,k,n) for(int i=k; (int)i<n; ++i)
#define rep(i,n,k) for(int i=n; (int)i>=k; --i)
#define all(v) v.begin(), v.end()
#define it ::iterator
#define forit(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)


const int inf = (int)1e9;
const ll INF = (ll)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int N = 100100;

int a,b,c;

int main(){
    
//freopen(fname"in", "r", stdin);
//freopen(fname"out", "w", stdout);

	cin>>a>>b>>c;

	int k = a*100 + b*10 + c;

	if(k%4 == 0)
		printf("YES");
	else
		printf("NO");
    
    return 0;
}







