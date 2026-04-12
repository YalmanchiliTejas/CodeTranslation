#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define FORR(i,m,n) for(int i=m;i>=n;i--)
#define pb(x) push_back(x) 
#define SORT(x) sort((x).begin(),(x).end())
#define INF 999999999999999

using namespace std;

#define int long long

int32_t main(){
	int h, w;
	cin >> h >> w;
	string str[h];
	REP(i, h) cin >> str[i];
	
	REP(i, h-1){
		REP(j, w-1){
			bool flag=false;
			FOR(k, j+1, w){
				if(str[i][k]=='#') flag=true;
			}
			FOR(k, i+1, h){
				if(str[k][j]=='#' && flag){
					cout << "Impossible" << endl;
					return 0;
				}
			}
		}
	}
	
	cout << "Possible" << endl;
}