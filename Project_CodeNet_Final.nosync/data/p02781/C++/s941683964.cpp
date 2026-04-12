#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

ll eql[110][5];
ll wngr[110][5];

int main(){
	string s; int k; cin >> s >> k;
	eql[1][1] = 1;
	wngr[1][1] = (s[0]-'0')-1;
	wngr[1][0] = 1;
	for( int i = 1; i < s.size(); ++i ){
		int d = s[i] - '0';
		wngr[i+1][0] = wngr[i][0];
		wngr[i+1][1] = 9*wngr[i][0] + wngr[i][1]; 
		wngr[i+1][2] = 9*wngr[i][1] + wngr[i][2];
		wngr[i+1][3] = 9*wngr[i][2] + wngr[i][3];
		if( d != 0 ){
			wngr[i+1][1] += eql[i][0]*(d-1) + eql[i][1];
			wngr[i+1][2] += eql[i][1]*(d-1) + eql[i][2];
			wngr[i+1][3] += eql[i][2]*(d-1) + eql[i][3];
		}
		if( d != 0 ) {
			eql[i+1][3] = eql[i][2];
			eql[i+1][2] = eql[i][1];
			eql[i+1][1] = eql[i][0];
		} else {
			eql[i+1][0] = eql[i][0];
			eql[i+1][1] = eql[i][1];
			eql[i+1][2] = eql[i][2];
			eql[i+1][3] = eql[i][3];
		}
	}
	cout << eql[s.size()][k] + wngr[s.size()][k] << endl;
}