#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PI; 
typedef pair<LL,LL> PLL;
typedef unsigned long long ULL;
typedef pair<double,double> PD;

#define FOR(x, b, e) for(int x = b; x<= (e); x++)
#define FORD(x, b, e) for(int x = b; x>= (e); x--)
#define REP(x, n) for(int x = 0; x<(n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define IN insert
#define ST first
#define ND second
#define INF 2000000011
#define MOD 1000000007
//2000000014
#define MAXSIZE 10010

int d;
string k;
LL wyn=0;
LL dp[MAXSIZE][11][110];

void u(LL &t1,LL &t2){
	t1+=t2;
	while(t1>=MOD)
		t1-=MOD;
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>k>>d;
	//if(d==2&&SIZE(k)<=9){
	//	dp[INF][INF][INF]++;		
	//}
	int n=SIZE(k);
	
	dp[n][0][0]=1;
	
	FORD(i,n-1,0){
		REP(j,10){
			REP(m,10){
				REP(p,d){
					u(dp[i][j][(p+j)%d],dp[i+1][m][p]);
				}
			}
		}
	}
	
	LL temp=0;
	REP(i,n){
		int cat=k[i]-'0';
		if(cat==0)
			continue;
			
		REP(j,cat)
			u(wyn,dp[i][j][(d-temp)%d]);
		temp+=cat;
		temp%=d;
	}
	
	if(temp%d==0)
		wyn++;
	
	cout<<(wyn-1+MOD)%MOD;
	return 0;
}

//1000000001 1
