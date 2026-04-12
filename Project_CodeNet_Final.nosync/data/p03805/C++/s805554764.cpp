#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;

int A[8][8]; //  i <-> j
int N, M;

int main() {

	cin >> N >> M;

	rep(i, N)
		rep(j, N)
	{
		A[i][j] = 0;
	}

	rep(i, M){
		int a, b;
		cin >> a >> b;
		a--; b--;
		A[a][b] = 1;
		A[b][a] = 1;
	}

	int ret = 0;

	vector<int> v;
	rep(i, N){ v.push_back(i); }
	do {
		if (v[0] != 0) continue;

		bool success = true;
		rep(i, N - 1){ success &= (A[v[i]][v[i + 1]] == 1); }
		if (success) ret += 1;

	} while (next_permutation(v.begin(), v.end()));     // 次の順列を生成

	cout << ret << endl;

}