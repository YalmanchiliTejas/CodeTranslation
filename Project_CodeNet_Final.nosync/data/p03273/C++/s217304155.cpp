#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H, vector<char>(W));

	REP(i, H){
		REP(j, W){
			cin >> a.at(i).at(j);
		}
	}

	vector<bool> row(H, false);
	vector<bool> col(W, false);

	REP(i, H){
		REP(j, W){
			if(a[i][j] == '#'){
				row[i] = true;
				col[j] = true;
			}
		}
	}

	REP(i, H){
			if(row[i]){
				REP(j, W){
					if(col[j]){
						cout << a[i][j];
					}
				}
				cout << endl;
			}
	}
}
