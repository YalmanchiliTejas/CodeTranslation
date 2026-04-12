#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;

char c[] = "BCDE", ans;
int a, b;

int main(){
	while (cin >> a >> b&&a + b){
		ans = 'A';
		int sum = a + b;
		REP(i, 4){
			cin >> a >> b;
			if (sum < a + b){
				ans = c[i];
				sum = a + b;
			}
		}
		cout << ans << " " << sum << endl;
	}

}