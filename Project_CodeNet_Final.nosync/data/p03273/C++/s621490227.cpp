#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));
	rep(i, h) rep(j, w){
		cin >> a[i][j];
	}
	
	//Rows
	rep(i, h){
		bool is_all_white = true;
		rep(j, w){
			if(a[i][j] == '#'){
				is_all_white = false;
			}
		}
		if(is_all_white){
			if(i < h - 1){
				for(int k = i; k < h - 1; k++){
					a[k] = a[k + 1];
				}
			}
			i--;
			h--;
		}
	}
	
	//Columms
	rep(j, w){
		bool is_all_white = true;
		rep(i, h){
			if(a[i][j] == '#'){
				is_all_white = false;
			}
		}
		if(is_all_white){
			if(j < w - 1){
				for(int k = j; k < w - 1; k++){
					rep(l, h){
						a[l][k] = a[l][k + 1];
					}
				}
			}
			j--;
			w--;
		}
	}
	
	rep(i, h){
		rep(j, w){
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}