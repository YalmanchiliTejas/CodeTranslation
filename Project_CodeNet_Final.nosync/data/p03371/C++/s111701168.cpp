#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;




int main(){
	int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
	if(a+b<2*c){
		cout << a*x+b*y << endl;
	}
	else{
		int d = min(x,y);
		int e = max(x,y);
		x-=d,y-=d;
		cout << min(2*c*e,2*c*d+a*x+b*y) << endl;
	}
}

