#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long int maxi(long long int A, long long int B) {
	return (A > B) ? A : B;
}
int main() {
	int H, W, c = 0;
	char ban;
	cin >> H >> W;
	for (int i = 0; i < H; i++)for (int j = 0; j < W; j++) {
		cin >> ban;
		if (ban == '#')c++;
	}
	if (c == W + H - 1) {
		cout << "Possible";
	}
	else cout << "Impossible";
}
