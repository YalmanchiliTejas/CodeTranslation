#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;
 
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
 
long gcd(long a, long b){
	if (a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
 
long lcm(long a, long b){
	return (a*b) / gcd(a,b);
}
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a < b) { a = b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a > b) { a = b; return 1; } return 0; }
 
typedef long long ll;
 
const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-10;

int n, m;
vector<int> g[8];
int cnt;

int main(){
	cin >> n >> m;
	
	REP(i,m){
		int a, b;
		cin >> a >> b;
		
		a--;
		b--;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	queue< pair<int, int> > q;
	q.push(make_pair(0,1));
	
	while( !q.empty() ){
		pair<int , int> c = q.front();
		q.pop();
		
		if (c.second == pow(2,n)-1){
			cnt++;
		}
		
		REP(i,g[c.first].size()){
			if (!(c.second >> g[c.first][i] & 1)){
				q.push(make_pair(g[c.first][i], c.second + pow(2,g[c.first][i])));
			}
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}