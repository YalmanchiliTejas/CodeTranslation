#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100;

int main() {
	int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
	int ans[3];
	ans[0]=2*max(x,y)*c;
	ans[1]=a*x+b*y;
	ans[2]=2*min(x,y)*c;
	if(x>=y) ans[2]+=a*(x-y);
	else ans[2]+=b*(y-x);
	sort(ans,ans+3);
	cout<<ans[0]<<endl;
}
