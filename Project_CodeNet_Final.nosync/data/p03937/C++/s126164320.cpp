#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int H, W; 
char A[8][8];

bool is_ok(vector<string> curr){
	bool res = true;
	rep (i, H) rep (j, W) res &= (curr[i][j] == A[i][j]);
	return res;
}

void disp_curr(vector<string> curr){
	cerr << endl;
	rep (i, H){
		rep (j, W){
			cerr << curr[i][j];
		} // end rep
		cerr << endl;
	} // end rep
}

bool dfs(int row, int col, vector<string> curr){
	curr[row][col] = '#';

	if (row == H - 1 && col == W - 1){
//		disp_curr(curr);
		return is_ok(curr);
	} // end if

	bool res = false;
	for (int i = 0; i < 2; ++i){
		if (i == 0){
			if (row + 1 < H && A[row + 1][col] == '#'){
				res |= dfs(row + 1, col, curr);
			} // end if
		}else{ // if (i == 1)		 
			if (col + 1 < W && A[row][col + 1] == '#'){
				res |= dfs(row, col + 1, curr);
			} // end if
		} // end if
	} // end for

	return res;
}

int main()
{
	rep (i, 8) rep (j, 8) A[i][j] = '.';	

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> H >> W;
	rep (i, H) rep (j, W) cin >> A[i][j];

	vector<string> curr(H, string(W, '.'));
	bool res = dfs(0, 0, curr);

	cout << (res ? "Possible": "Impossible") << endl;			

	return 0;
}