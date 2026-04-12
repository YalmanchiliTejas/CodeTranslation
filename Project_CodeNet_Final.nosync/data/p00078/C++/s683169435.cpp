#include <iostream>
#include <vector>
#include <iomanip>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
	int n;
	while (cin >> n && n ){
		vector<vector<int> > b (n, vector <int> (n, 0 ) );
		int row = n/2+1, col = n/2;
		int cnt = 1;
		b[row][col] = cnt++;
		
		while (cnt <= n*n ){
			row = (row + 1) % n;
			col = (col + 1) % n;
			if (b[row][col] == 0 ){
				b[row][col] = cnt;
			}else{
				int nr = (row+1) % n;
				int nc = (n + col - 1 ) % n;
				while (b[nr][nc] != 0 ){
					nr = (row+1) % n;
					nc = (n + col - 1 ) % n;
				} // end while
				b[nr][nc] = cnt;
				row = nr; col = nc;
			} // end if
			cnt++;
		} // end while
		rep (i, n ){
			rep (j, n ){
				cout << setw(4) << b[i][j];
			} // end rep
			cout << endl;
		} // end rep
	} // end while

	return 0;
}