#include<iostream>
#include<math.h>
#include<algorithm>
#define ll long long int
#define FOR(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n)

using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	char a[h][w];
	int g[h], r[w];
	REP(i,h) g[i] = 0;
	REP(i,w) r[i] = 0;
	REP(i,h){
		REP(j,w){
			cin >> a[i][j];
			if(a[i][j] == '.'){
				g[i]++;
				r[j]++;
			}
		}
	}

	REP(i,h){
		REP(j,w){
			if(g[i] != w && r[j] != h){
				cout << a[i][j];
			}
		}
		if(i == h) cout << endl;
		else if(g[i] != w) cout << endl;
	}
	return 0;
}
