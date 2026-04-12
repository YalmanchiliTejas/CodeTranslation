#include<iostream>
#include<string>
using namespace std;
int main() {
	int x, kazu, w, l, d, ten[11], dai, kazu2, ans[55][11],kaisuu[55];
	string kuni[55][11], taihi[11];
	kazu = 0;
	while (1) {
		dai = 0;
		cin >> x;
		if (x == 0) {
			goto a;
		}
		kazu = kazu + 1;
		for (int i = 1; i <= x; i++) {
			cin >> taihi[i] >> w >> l >> d;
			ten[i] = w * 3 + d;
			if (dai < ten[i]) {
				dai = ten[i];
			}
		}
		kazu2 = 0;
		for (int z = dai; z >= 0; z--) {
			kaisuu[kazu] = x;
			for (int i = 1; i <= x; i++) {
				if (ten[i] == z) {
					kazu2 = kazu2 + 1;
					kuni[kazu][kazu2] = taihi[i];
					ans[kazu][kazu2] = ten[i];
				}
			}
		}
	}
a:;
	for (int i = 1; i <= kazu; i++) {
		for (int z = 1; z <= kaisuu[i]; z++) {
			cout << kuni[i][z] << "," << ans[i][z] << endl;
		}
		if (i != kazu) {
			cout << endl;
		}
	}
}
