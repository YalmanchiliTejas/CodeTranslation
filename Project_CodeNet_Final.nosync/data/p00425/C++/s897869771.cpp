#include<iostream>
#include<string>
using namespace std;
int main() {
	int ans[11], an, n,sai[11],sai1[11];
	string a;
	an = 0;
	while (1) {
		cin >> n;
		if (n == 0) {
			goto a;
		}
		an = an + 1;
		ans[an] = 0;
		for (int i = 1; i <= 6; i++) {
			sai[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a;
			for (int z = 1; z <= 6; z++) {
				sai1[z] = sai[z];
			}
			if (a == "North") {
				sai[1] = sai1[2];
				sai[2] = sai1[6];
				sai[6] = sai1[5];
				sai[5] = sai1[1];
			}
			if (a == "East") {
				sai[1] = sai1[4];
				sai[3] = sai1[1];
				sai[6] = sai1[3];
				sai[4] = sai1[6];
			}
			if (a == "West") {
				sai[1] = sai1[3];
				sai[3] = sai1[6];
				sai[6] = sai1[4];
				sai[4] = sai1[1];
			}
			if (a == "South") {
				sai[1] = sai1[5];
				sai[2] = sai1[1];
				sai[6] = sai1[2];
				sai[5] = sai1[6];
			}
			if (a == "Right") {
				sai[2] = sai1[3];
				sai[3] = sai1[5];
				sai[5] = sai1[4];
				sai[4] = sai1[2];
			}
			if (a == "Left") {
				sai[2] = sai1[4];
				sai[3] = sai1[2];
				sai[4] = sai1[5];
				sai[5] = sai1[3];
			}
			ans[an] = ans[an] + sai[1];
		}
	}
a:;
	for (int i = 1; i <= an; i++) {
		cout << ans[i]+1 << endl;
	}
}
