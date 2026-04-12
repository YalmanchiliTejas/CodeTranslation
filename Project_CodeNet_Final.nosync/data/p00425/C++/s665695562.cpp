#include <bits/stdc++.h>
using namespace std;

struct saikoro{
	int ue, shita, migi, hidari, oku, temae;
};
saikoro sai = {1, 6, 3, 4, 5, 2};

void north() {
	int buf = sai.oku;
	sai.oku = sai.ue;
	sai.ue = sai.temae;
	sai.temae = sai.shita;
	sai.shita = buf;
}
void south() {
	int buf = sai.temae;
	sai.temae = sai.ue;
	sai.ue = sai.oku;
	sai.oku = sai.shita;
	sai.shita = buf;
}
void east() {
	int buf = sai.migi;
	sai.migi = sai.ue;
	sai.ue = sai.hidari;
	sai.hidari = sai.shita;
	sai.shita = buf;
}
void west() {
	int buf = sai.hidari;
	sai.hidari = sai.ue;
	sai.ue = sai.migi;
	sai.migi = sai.shita;
	sai.shita = buf;
}
void right() {
	int buf = sai.hidari;
	sai.hidari = sai.temae;
	sai.temae = sai.migi;
	sai.migi = sai.oku;
	sai.oku = buf;
}
void left() {
	int buf = sai.migi;
	sai.migi = sai.temae;
	sai.temae = sai.hidari;
	sai.hidari = sai.oku;
	sai.oku = buf;
}

int main() {
	int n, ans;
	string s;
	while(1) {
		sai.ue = 1; sai.shita = 6; sai.migi = 3;
		sai.hidari = 4; sai.oku = 5; sai.temae = 2;
		ans = 0;
		cin >> n;
		if(n == 0) return 0;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s == "North") {
				north();
				ans += sai.ue;
			}else if(s == "South") {
				south();
				ans += sai.ue;
			}else if(s == "East") {
				east();
				ans += sai.ue;
			}else if(s == "West") {
				west();
				ans += sai.ue;
			}else if(s == "Right") {
				right();
				ans += sai.ue;
			}else if(s == "Left") {
				left();
				ans += sai.ue;
			}
		}
		cout << ans + 1 << endl;
	}
}