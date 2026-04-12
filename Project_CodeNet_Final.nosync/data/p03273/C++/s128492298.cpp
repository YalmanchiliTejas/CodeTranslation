#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h>



using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;


//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)



int main(void){

	int H, W; cin >> H >> W;
	vector<string> a(H);
	REP(i,H) cin >> a[i];

	vector<bool> goodh(H,false);
	vector<bool> goodw(W,false);

	REP(i,H){
		REP(j,W){
			if(a[i][j] == '#'){
				goodh[i] = true;
				goodw[j] = true;
			}
		}
	}

	REP(i,H){
		if(goodh[i]){
			REP(j,W){
				if(goodw[j] == true) cout << a[i][j];
			}
			cout << endl;
		}

	}


	return 0;

}
