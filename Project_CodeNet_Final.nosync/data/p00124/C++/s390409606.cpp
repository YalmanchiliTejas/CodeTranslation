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

ll n, a, b, c;
string s;

vector<string> vs;
vector<P> vi;

bool flag(P i, P j){
	if (i.first == j.first){
		return i.second < j.second;
	}
	else return i.first > j.first;
}

int main(){
	bool f = 0;
	while (cin >> n&&n){
		REP(i, n){
			cin >> s >> a >> b >> c;
			vi.push_back(make_pair(a * 3 + c, i));
			vs.push_back(s);
		}
		sort(ALL(vi), flag);
		if (f)cout << endl;
		REP(i, vi.size()){
			cout << vs[vi[i].second] << "," << vi[i].first << endl;
		}
		f = 1;
		vs.clear();
		vi.clear();
	}
}