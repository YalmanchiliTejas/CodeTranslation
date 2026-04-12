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

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;

ll a, b, q;
vector<P> v;

bool flag(P a,P b){
	if (a.first == b.first){
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(){
	while (scanf("%d,%d", &a, &b) && a + b){
		v.push_back(P(b, a));
	}
	sort(ALL(v), flag);
	while (cin >> q){
		ll co = 0, k = -1;
		REP(i, v.size()){
			if (v[i].first != k){
				co++;
				k = v[i].first;
			}
			if (v[i].second == q){
				cout << co << endl;
				break;
			}
		}
	}
}