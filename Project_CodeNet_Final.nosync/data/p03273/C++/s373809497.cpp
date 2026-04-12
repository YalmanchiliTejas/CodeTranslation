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
	bool rows[h][w];
	bool cols[w][h];
	vi okr;
	vi okc;
	
	char c;
	REP(i, 0, h){
		REP(j, 0, w){
			cin >> c;
			grid[i][j] = c;
			rows[i][j] = (c== '#'?false:true);
			cols[j][i] = (c== '#'?false:true);
		}
	}
	REP(i, 0, h){
		bool ok = true;
		REP(j, 0, w){
			if(!rows[i][j]){
				ok = false;
				break;
			}
		}
		if(!ok) okr.PB(i);
	}
	
	REP(i, 0, w){
		bool ok = true;
		REP(j, 0, h){
			if(!cols[i][j]){
				ok = false;
				break;
			}
		}
		if(!ok) okc.PB(i);
	}
	
	for(auto it=okr.begin(); it < okr.end(); it++){
		for(auto it1=okc.begin(); it1 < okc.end(); it1++){
			cout << grid[*it][*it1];
		}
		cout << endl;
	}
	
	
				

}
