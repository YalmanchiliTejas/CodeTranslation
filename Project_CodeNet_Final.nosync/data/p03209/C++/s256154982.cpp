#include "bits/stdc++.h"

using namespace std;

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
#define fir first
#define sec second

const int INF = 1e9 + 10;
//const ll INF = 1e18 + 10LL;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
const double EPS = 1e-10;
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)
ll MOD = 1e9 + 7;

//http://drken1215.hatenablog.com/entry/2019/05/13/114600 写経

ll rec(int n, ll x) {
	if (n == 0) return 1;
	ll len = (1LL<<(n + 1)) - 3;
	ll num = (1LL<<n) - 1;
	if (x == 1) return 0;
	else if (x <= len + 1) return rec(n - 1, x - 1);
	else if (x == len + 2) return num + 1;
	else if (x <= (len + 1) * 2) return num + 1 + rec(n - 1, x - len - 2);
	else return num * 2 + 1;
}

int main(void){
	int N; ll X;
	cin>>N>>X;

	cout<< rec(N, X) <<endl;
	
	return 0;
}