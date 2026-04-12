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

#define MAXSIZE 3005

LL tab[MAXSIZE];
LL dp[MAXSIZE][MAXSIZE];

int n;

int main(){	//wniosek: rozkminiaj wiecej dp[l][r];
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	FOR(i,1,n)
		cin>>tab[i];
	
	FOR(dl,1,n){		
		FOR(l,1,n){
			int r=dl+l-1;
			if(r>n)
				break;
		
			if(n%2==dl%2)	//hey Taro!
				dp[l][r]=max(dp[l][r-1]+tab[r],dp[l+1][r]+tab[l]);
			else
				dp[l][r]=min(dp[l][r-1]-tab[r],dp[l+1][r]-tab[l]);
			//cout<<l<<" "<<r<<"\n";
		}
	}
	
	cout<<dp[1][n];
	return 0;
}
