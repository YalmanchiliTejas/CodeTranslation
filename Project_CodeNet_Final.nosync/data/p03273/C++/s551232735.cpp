#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
char a[100][101];
bool rm_h[100], rm_w[100];
 int main() {
	 int H, W;
	 cin >> H >> W;
	 for (int i = 0; i < H; i++) cin >> a[i];
	 for (int i = 0; i < H; i++) {
		 bool empty = 1;
		 for (int j = 0; j < W; j++) {
			 if (a[i][j] == '#') {
				 empty = 0;
				 break;
			 }
		 }
		 if (empty) rm_h[i] = 1;
	 }
	 for (int i = 0; i < W; i++) {
		 bool empty = 1;
		 for (int j = 0; j < H; j++) {
			 if (a[j][i] == '#') {
				 empty = 0;
				 break;
			 }
		 }
		 if (empty) rm_w[i] = 1;
	 }
	 for (int i = 0; i < H; i++) {
		 if (rm_h[i]) continue;
		 for (int j = 0; j < W; j++) {
			 if (rm_w[j]) continue;
			 cout << a[i][j];
		 }
		 cout << endl;
	 }
}