#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)


int main(void){

	int n; cin >> n;
	vector<string> S(n);
	REP(i,n) cin >> S[i];

	REP(i,26){
		int min_value = 100;
		REP(j,n){
			int cnt = 0;
			REP(k,S[j].length()){
				char c = 'a' + i;
				if(c == S[j][k]) cnt++;
			}
			min_value = min(min_value, cnt);
		}
		REP(j,min_value) cout << (char)('a' + i);
	}
	cout << endl;




	return 0;

}
