#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int H, W; cin >> H >> W;
	int a = 0;
	for (int i = 0; i < H*W; i++){
		char c; cin >> c;
		if (c == '#')++a;
	}
	cout << ((a == H + W - 1) ? "P" : "Imp") << "ossible\n";
}