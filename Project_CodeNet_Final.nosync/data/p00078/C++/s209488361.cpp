#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void magicSquare(vector<vector<int> > &v1) {
  int n = v1.size();
  int r = (n / 2 + 1), c = n / 2;
  
  v1[r][c] = 1;
  for(int cnt = 2; cnt <= n * n; ++cnt) {
	r = (r == n - 1 ? 0 : r + 1);
	c = (c == n - 1 ? 0 : c + 1);

	while(v1[r][c] != 0) {
	  r = (r == n - 1 ? 0 : r + 1);
	  c = (c == 0 ? n - 1 : c - 1);
	}
	v1[r][c] = cnt;
  }
}

void printVector(vector<vector<int> > &v1) {
  int n = v1.size();
  for(int i = 0; i < n; ++i) {
	  for(int j = 0; j < n; ++j) {
		cout << right << setw(4) << v1[i][j];
	  }
	  cout << endl;
	}
}

int main() {
  int n;
  while(cin >> n) {
	if(n == 0) break;

	vector<vector<int> > v1(n, vector<int>(n, 0));
	magicSquare(v1);
	printVector(v1);
  }
  return 0;
}