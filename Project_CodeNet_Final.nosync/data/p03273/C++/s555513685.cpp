#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	int i, j, k;
	int H, W;
	int num_flag;
	cin >> H >> W;

	char a[H][W + 1];
	char dummy[W + 1];
	int lines = 0;

	for (i = 0; i < W; i++) 
		dummy[i] = '.';

	dummy[W] = '\0';
	
	
	for (i = 0; i < H; i++) {
	    cin >> a[i];
		a[i][W] = '\0';

		if (strncmp(a[i], dummy, W + 1) == 0) {
			for (j = 0; j < W + 1; j++) 
				a[i][j] = '\0';
			i--;
			lines++;
		}
	}

	char result[H - lines][W + 1];
	int result_index = 0;

	for (i = 0; i < W + 1; i++) {
		num_flag = 0;
		for (j = 0; j < H - lines; j++) {
			if (a[j][i] == '#') {
				num_flag = 1;
				break;
			}
		}
		if (num_flag == 1) {
			for (j = 0; j < H - lines; j++) {
				result[j][result_index] = a[j][i];
			}
			result_index++;
		}
	}

	for (i = 0; i < H - lines; i++) {
		result[i][result_index] = '\0';
	}
				
	
    for (i = 0; i < H - lines; i++) {
		cout << result[i];
		cout << "\n";
	}
			

	return 0;
}
