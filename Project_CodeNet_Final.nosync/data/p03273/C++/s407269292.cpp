#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int h, w;
	cin >> h >> w;
	char grid[h][w];
	vector<bool> rows(h, false);
	vector<bool> cols(w, false);
	char c;
	
	REP(i, 0, h){
		REP(j, 0, w){
			cin >> c;
			rows[i] = (c=='#'?true:rows[i]);
			cols[j] = (c=='#'?true:cols[j]);
			grid[i][j] = c;
		}
	}
	
	REP(i, 0, h){
		if(!rows[i]) continue;
		REP(j, 0, w){
			if(cols[j]) cout << grid[i][j];
		}
		cout << endl;
	}
			
	
				

}
