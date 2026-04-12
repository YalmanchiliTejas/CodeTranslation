#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); i++)
#define RREP(i, n) for(int i=0; i>(int)(n); i--)
#define ALL(v) v.begin(), v.end()
#define INF 2e9
typedef long long ll;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return 1;}return 0;}

using namespace std;

int N;
ll a[3333];
ll dp[3333][3333];
bool flag[3333][3333];

ll f(int x, int y)
{
	if(flag[x][y]){
		return dp[x][y];
	}
	flag[x][y] = true;
	if(x==y){
		return dp[x][y] = a[x];
	}
	return dp[x][y] = max(a[x]-f(x+1, y), a[y]-f(x, y-1));
}

int main(void)
{
	cin >> N;
	REP(i, N){
		cin >> a[i];
	}
	REP(i, N){
		REP(k, N){
			flag[i][k] = false;
		}
	}
	cout << f(0, N-1) << "\n";
	return 0;
}
