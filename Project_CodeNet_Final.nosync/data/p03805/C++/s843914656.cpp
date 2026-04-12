#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 0x3fffffff;

int N, M, ans=0;
vector<int> v[10];
int dfs(int n, int d, bool visited[10]){
//	cout << n << " " << d << " " << endl;
	if( d == N ) return 1;
	int ret = 0;
	visited[n] = true;
	for(auto t: v[n]) if( !visited[t] ){
		ret += dfs(t, d+1, visited);
	}
	visited[n] = false;
	return ret;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int a[100], b[100];

	cin >> N >> M;
	rep(i,M){
		cin >> a[i] >> b[i];
		v[ a[i] ].push_back( b[i] );
		v[ b[i] ].push_back( a[i] );
	}

	bool visited[10]={};
	ans = dfs(1, 1, visited);

	cout << ans << endl;

	return 0;
}
