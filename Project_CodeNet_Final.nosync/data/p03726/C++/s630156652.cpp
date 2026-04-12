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
 
 
vector<int> edge[100005];
bool d[100005] = {};
bool b[100005] = {};
bool ans = false;
int start = -1;
int dfs(int n, int b){
	//cout << "dfs: " << n << " " << b << endl;
	if( d[n] ){
		start = n;
		return -1;
	}
	d[n] = true;
	if( edge[n].size() == 1 ) return 1;
	vector<int> v;
	for(auto t: edge[n]) if(t != b){
		v.push_back( dfs(t, n) );
	}
	int odd = 0;
	int even = 0;
	for(auto t: v){
		if( t >= 0 && (t % 2) ) odd++;
		if( t >= 0 && (t % 2 == 0) ) even++;
		//cout << t << " ";
	}
	//cout << endl;
	//cout << n << "," << b << "  odd:" << odd << " even:" << even << endl;
	if( odd > 1 ){
		ans = true;
		//cout << "true " << ret << endl;
	}
	if( v.size() == even ) return 1;
	if( odd == 1 ) return 0;
	return ( v.size()==1 ? v[0]+1 : -1 );
}
 
int find(int n, int b){
	if( edge[n].size() > 2 ) return n;
	for(auto t: edge[n]) if( t != b ){
		return find(t, n);
	}
	return b;
}
 
int main(){
	//ios_base::sync_with_stdio(0);
	int N;
 
	cin >> N;
	rep(i,N-1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
 
	rep(i,N){
		//cout << "loop" << endl;
		if( edge[i].size() == 1 ){
			Fill( d, false );
			int st = edge[i][0];
			if( b[st] ) continue;
			b[ st ] = true;
			dfs( st, -1 );
			break;
		}
		if( edge[i].size() > 2 ){
			//int st = find(edge[i][0], i);
			int st = i;
			if( b[st] ) continue;
			Fill( d, false );
			b[ st ] = true;
			dfs( st, -1 );
			if( ans ) break;
		}
	}
 
	cout << (ans ? "First" : "Second" ) << endl;
 
	return 0;
}