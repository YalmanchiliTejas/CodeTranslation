#include <bits/stdc++.h>
#include <unistd.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb() fflush(stdout);

using namespace std;

const int max_n = 12345;
const int mod = 1e9 + 7;
char s[max_n];

int n, d;
int dp[max_n][105][2];



int main () {
	scanf("%s", s);
	read(d); n = strlen(s);
	FOR(j,0,10) dp[n-1][j%d][0] += 1;
	FOR(j,0,s[n-1]-'0'+1) dp[n-1][j%d][1] += 1;

	FORD(i,n-2,0) {
		FOR(j,0,d) {
			dp[i][j][0] = dp[i][j][1] = 0;
			FOR(u,0,10) {
				dp[i][j][0] += dp[i+1][(j+10*d-u)%d][0];
				dp[i][j][0] %= mod;
			}
			FOR(u,0,s[i]-'0') {
				dp[i][j][1] += dp[i+1][(j+10*d-u)%d][0];
				dp[i][j][1] %= mod;
			}
			dp[i][j][1] += dp[i+1][(j+10*d-(s[i]-'0'))%d][1];
			dp[i][j][1] %= mod;

		}
	}
	printf("%d\n", (dp[0][0][1]+mod-1)%mod);
}	



