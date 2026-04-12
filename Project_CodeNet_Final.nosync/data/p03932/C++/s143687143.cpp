#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(8000000, -1);
int f(vector<vector<int>> &A, int y1, int x1, int y2, int x2){
	int X = (y1 * 200 + x1) * 200 + y2;
	if (dp[X] != -1){
		return dp[X];
	} else {
		int tmp = A[y1][x1] + A[y2][x2];
		if (y1 == y2 && x1 == x2){
			tmp /= 2;
		}
		int ans = 0;
		if (y1 > 0 && y2 > 0){
			ans = max(ans, f(A, y1 - 1, x1, y2 - 1, x2));
		}
		if (y1 > 0 && x2 > 0){
			ans = max(ans, f(A, y1 - 1, x1, y2, x2 - 1));
		}
		if (x1 > 0 && y2 > 0){
			ans = max(ans, f(A, y1, x1 - 1, y2 - 1, x2));
		}
		if (x1 > 0 && x2 > 0){
			ans = max(ans, f(A, y1, x1 - 1, y2, x2 - 1));
		}
		ans += tmp;
		dp[X] = ans;
		return ans;
	}
}
int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<int>> A(H, vector<int>(W));
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> A[i][j];
		}
	}
	cout << f(A, H - 1, W - 1, H - 1, W - 1) << endl;
}