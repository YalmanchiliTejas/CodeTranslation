#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

bool tate[100];
bool yoko[100];


int main(){
	int h, w;
	cin >> h >> w;
	char stage[100][100];
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> stage[i][j];
		}
	}

	for (int i = 0; i < h; i++){
		int coun = 0;
		for (int j = 0; j < w; j++){
			if (stage[i][j] == '.') coun++;
		}
		if (coun == w) yoko[i] = true;
	}

	for (int i = 0; i < w; i++){
		int coun = 0;
		for (int j = 0; j < h; j++){
			if (stage[j][i] == '.') coun++;
		}
		if (coun == h) tate[i] = true;
	}

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			if (!yoko[i] && !tate[j]) cout << stage[i][j];
		}
		if (!yoko[i]) cout << endl;
	}
	return 0;
}