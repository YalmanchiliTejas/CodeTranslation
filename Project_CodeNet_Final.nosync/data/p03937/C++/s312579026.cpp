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
#include <fstream>
#include <bitset>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 10e7+9
#define MOD 1000000007
#define EPS 1e-10
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

int h, w;
char field[100][100];
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

void solve(int y, int x){
	field[y][x] = '.';
	REP(i, 2){
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < w&&ny >= 0 && ny < h){
			if (field[ny][nx] == '#'){
				solve(ny, nx);
				break;
			}
		}
	}
}

int main(){
	cin >> h >> w;
	REP(i, h){
		REP(j, w){
			cin >> field[i][j];
		}
	}
	solve(0, 0);
	REP(i, h){
		REP(j, w){
			if (field[i][j] == '#'){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
}