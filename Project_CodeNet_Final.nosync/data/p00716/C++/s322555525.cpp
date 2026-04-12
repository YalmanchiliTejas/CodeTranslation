#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>

using namespace std;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main(){
	int T;
	cin >> T;
	REP(t,T){
		int iM,ret=0,y,k;
		cin >> iM >> y >> k;
		REP(i,k){
			int r, R, M=iM, t;
			double ratio;
			R=0;
			cin >> r >> ratio >> t;
			if(r==1)REP(j, y)M += M*ratio - t;
			if(r==0){
				REP(j, y){
					R += M*ratio;
					M -= t;
				}
				M+=R;
			}
			ret = max(ret, M);
		}
		cout << ret << endl;
	}
	return 0;
}