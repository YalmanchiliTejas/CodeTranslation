#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

char grid[101][101];
bool eraseX[101];
bool eraseY[101];

int main()
{
	memset(grid, 0, sizeof(grid));
	memset(eraseX, false, sizeof(eraseX));
	memset(eraseY, false, sizeof(eraseY));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H, W; cin >> H >> W;
	rep (i, H){
		rep (j, W){
			cin >> grid[i][j];
		} // end rep
	} // end rep

	bool update = false;
	while(true){
		update = false;
		rep (i, H){
			if (eraseY[i]) continue;
			int cnt = 0;
			int total = 0;
			rep (j, W){
				if (eraseX[j]) continue;
				++total;
				cnt += (int)(grid[i][j] == '.');
			} // end rep
			if (total == cnt){
				eraseY[i] |= true;
				update|= true;
			} // end if
		} // end rep

		rep (j, W){
			if (eraseX[j]) continue;
			int cnt = 0;
			int total = 0;
			rep (i, H){
				if (eraseY[i]) continue;
				++total;
				cnt += (int)(grid[i][j] == '.');
			} // end rep
			if (total == cnt){
				eraseX[j] |= true;
				update |= true;
			} // end if
		} // end rep
		if (!update){
			break;
		} // end if
	} // end while

	rep (i, H){
		if (eraseY[i]) continue;
		rep (j, W){
			if (eraseX[j]) continue;
			cout << grid[i][j];
		} // end rep
		cout << endl;
	} // end rep
		
	return 0;
}