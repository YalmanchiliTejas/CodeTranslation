#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz size()
#define FORN(i,j,n) for(long long i=j; i<(long long)n;i++) 
#define FOR(i,n) FORN(i,0,n)
#define FORIT(i,x) for( auto i = x.begin() ; i != x.end() ; i++ )
#define MOD 998244353LL
#define LIM 262150
#define ones(x) __builtin_popcount(x)
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
using namespace std;
 
typedef long long ll ;
typedef unsigned long long ull ;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
ll n; 
ll arr[3005];
ll dp[3005][3005];
int main() {
	fastio;
	cin>> n;
	FOR(i,n) cin>> arr[i];
	FORN(i,1,n+1){
		FOR(j,n){
			if(j+i > n) continue;
			if(i == 1){ dp[i][j] = arr[j]; continue; }
			dp[i][j] = max(arr[j]-dp[i-1][j+1],arr[j+i-1]-dp[i-1][j]);
		}
	}
	cout<< dp[n][0] << '\n';
	return 0;
}