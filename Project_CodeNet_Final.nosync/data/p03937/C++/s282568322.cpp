#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int dx[] = {1,0};
const int dy[] = {0,1};

void solve(){
	int H,W;
	cin >> H >> W;
	vector<string> A(H);
	for(auto &s : A) cin >> s;
	if(A[0][0] != '#' || A[H-1][W-1] != '#'){
		cout << "Impossible" << endl;
		return;
	}
	A[0][0] = '.';
	int i = 0, j = 0;
	while(i != H-1 || j != W-1){
		bool flag = true;
		for(int k = 0; k < 2; k++){
			int ii = i + dy[k];
			int jj = j + dx[k];
			if(ii == H || jj == W) continue;
			if(A[ii][jj] == '#'){
				flag = false;
				A[ii][jj] = '.';
				i = ii;
				j = jj;
				break;
			}
		}
		if(flag) break;
	}
	A[H-1][W-1] = '.';
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){
			//cout << A[y][x];
			if(A[y][x] == '#') {
				cout << "Impossible" << endl;
				return;
			}
		}
	}
	cout << "Possible" << endl;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
