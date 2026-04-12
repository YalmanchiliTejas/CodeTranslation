#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
void magicSquare(vector<vector<int> > &v1) {
  int n = v1.size();
  int row = (n / 2 + 1), column = n / 2;
  
  v1[row][column] = 1;
  for(int cnt = 2; cnt <= n * n; ++cnt) {
	row = (row == n - 1 ? 0 : row + 1);
	column = (column == n - 1 ? 0 : column + 1);

	while(v1[row][column] != 0) {
	  row = (row == n - 1 ? 0 : row + 1);
	  column = (column == 0 ? n - 1 : column - 1);
	}
	v1[row][column] = cnt;
  }
}

int main() {
  int n;
  while(cin >> n) {
	if(n == 0) break;

	vector<vector<int> > v1(n, vector<int>(n, 0));
	magicSquare(v1);
	for(int i = 0; i < n; ++i) {
	  for(int j = 0; j < n; ++j) {
		cout << right << setw(4) << v1[i][j];
	  }
	  cout << endl;
	}
  }
  return 0;
}