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
typedef pair<P, char> PC;

struct dice{
	int side[6];
	dice(){ side[4] = 1, side[5] = 6, 
		side[0] = 5, side[1] = 3, side[2] = 2, side[3] = 4; }
};

void solve(dice* o, int i, int j, int k, int l){
	int p = o->side[i];
	o->side[i] = o->side[j];
	o->side[j] = o->side[k];
	o->side[k] = o->side[l];
	o->side[l] = p;
}

int n;
string s;

int main(){
	while (cin >> n&&n){
		dice d;
		int sum = 1;
		REP(i, n){
			cin >> s;
			if (s == "North") solve(&d, 4, 2, 5, 0);
			else if (s == "East")solve(&d, 4, 3, 5, 1);
			else if (s == "West")solve(&d, 4, 1, 5, 3);
			else if (s == "South")solve(&d, 4, 0, 5, 2);
			else if (s == "Right")solve(&d, 2, 1, 0, 3);
			else if (s == "Left")solve(&d, 2, 3, 0, 1);
			sum += d.side[4];
		}
		cout << sum << endl;
	}
}