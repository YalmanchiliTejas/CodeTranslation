#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define EPS (1e-7)
#define INF 1e9

typedef long long ll;
typedef pair<int,int>P;

int main(){
	int H,W;
	cin>>H>>W;
	string a[H];
	REP(i,H){
		cin>>a[i];
	}
	string ans="Possible";
	REP(i,H){
		REP(j,W){
			if(i+1<H && j+1<W){
				if(a[i+1][j]=='#' && a[i][j+1]=='#' && (a[i][j]=='#' || a[i+1][j+1]=='#')){
					ans="Impossible";
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}