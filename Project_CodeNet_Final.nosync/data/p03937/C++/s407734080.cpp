#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int row, column;
	scanf("%d %d", &row, &column);
	char** board = new char*[row + 1];
	for (int i = 0; i < row + 1; i++) {
		board[i] = new char[column + 1];
	}
	char c;
	scanf("%c", &c);
	for (int i = 0; i < row + 1; i++) {
		for (int j = 0; j < column + 1; j++) {
			scanf("%c", &(board[i][j]));
		}
	}

	bool flag = true;
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < column; j++) {
			if (board[i - 1][j] == '#' && board[i][j - 1] == '#') {
				flag = false;
				break;
			}
		}
	}
	if (flag  == true) {
		printf("Possible\n");
	}
	else {
		printf("Impossible\n");
	}
}