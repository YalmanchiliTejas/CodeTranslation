#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <functional>
#include <string.h>

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))


#define MOD 1000000007

typedef pair<int,int>P;
#define INF (1<<29)
 
struct edge{
	int dst;
	ll cost;
	edge(int dst, ll cost){
		this->dst=dst; this->cost=cost;
	}

};

int n;
ll a[55];


int main(){
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	ll ans = 0;
	while (1) {
		bool flg = false;
		ll del = 0;

		rep(i, n) {
			if (a[i] / n > 0) {
				del = a[i] / n;
				ans +=del;
				a[i] -= a[i] / n * n;
				rep(j, n) {//
					if (i != j)
						a[j] += del;
				}
			}

		}
		if (del == 0)
			break;
	}
	cout << ans << endl;
	return 0;
}
