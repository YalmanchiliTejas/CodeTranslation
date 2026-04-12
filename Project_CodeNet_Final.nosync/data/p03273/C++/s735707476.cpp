#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
using namespace std;

int main() {
	int h, w;
  	char a[105][105];
  	bool row[105], col[105];
  	REP(i, 105) row[i] = false;
  	REP(i, 105) col[i] = false;
    cin >> h;
  	cin >> w;
  
  	//入力
    REP(i, h){
     	 REP(j, w){
    		cin >> a[i][j];
		}
    }
  
  	//処理
    REP(i, h){
        REP(j, w){
    		if(a[i][j] == '#') {
              	row[i] = true;
              	col[j] = true;
            }
		}
    }

  	//出力
    REP(i, h){
      	REP(j, w){
          	if(row[i] == true && col[j] == true) {
		    		cout << a[i][j];
            }
		}
    	if(row[i] == true) cout << "\n";
    }
	return 0;
}