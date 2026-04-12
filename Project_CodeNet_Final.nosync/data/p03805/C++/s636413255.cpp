#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for(int i = 0;i < (n);++i)
#define REPLL(i, n) for(ll i = 0;i < (n);++i)

#define endl "\n"
#define pb push_back
#define MOD 1000000007LL
#define PI 3.1415926

typedef long long ll;

template <typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}
template <typename T> inline T POW(T a,T b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

int n, m;
bool graph[8][8];
int dfs(int pos, bool visit[8]){
	bool allvisit = 1;
	REP(i, n){
		if(!visit[i]) allvisit = 0;
	}
	if(allvisit) return 1;

	int res = 0;
	REP(i, n){
		if(!graph[pos][i]) continue;
		if(visit[i]) continue;

		visit[i] = 1;
		res += dfs(i, visit);
		visit[i] = 0;
	}

	return res;
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	int a, b;
	REP(i, m){
		cin >> a >> b;
		graph[a-1][b-1] = graph[b-1][a-1] = 1;
	}

	bool visited[8];
	REP(i, n) visited[i] = 0;
	visited[0] = 1;

	cout << dfs(0, visited) << endl;

	return 0;
}