#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int N,H[30],ans=1;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = 1; i < N; i++) {
		bool can = 1;
		for (int j = 0; j < i; j++) {
			if (H[i] < H[j]) { can = 0; break; }
		}
		if (can)ans += 1;
	}
	cout << ans << endl;

}
