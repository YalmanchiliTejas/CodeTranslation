#include<iostream>
#include<string>
#include<vector>

using namespace std;
#define Sheep true
#define Wolf false

int n;
string s;

bool func(bool z, bool o) {
	bool a[100000] = {};
	a[0] = z;
	a[1] = o;
	for (int i = 1; i != s.size() - 1; i++) {
		if (s[i] == 'o') {//s[i]が○だったら
			if (a[i] && a[i - 1])a[i + 1] = Sheep; //a[i]とa[i-1]が羊
			else if (a[i] && !a[i - 1])a[i + 1] = Wolf;//a[i]が羊,a[i-1]が狼
			else if (!a[i] && a[i - 1])a[i + 1] = Wolf;//a[i]が狼、a[i-1]が羊
			else if (!a[i] && !a[i - 1])a[i + 1] = Sheep;//a[i]とa[i-1]が狼				
		}
		else { //s[i]が×だったら
			if (a[i] && a[i - 1])a[i + 1] = Wolf; //a[i]とa[i-1]が羊
			else if (a[i] && !a[i - 1])a[i + 1] = Sheep;//a[i]が羊,a[i-1]が狼
			else if (!a[i] && a[i - 1])a[i + 1] = Sheep;//a[i]が狼、a[i-1]が羊
			else if (!a[i] && !a[i - 1])a[i + 1] = Wolf;//a[i]とa[i-1]が狼				
		}
	}
	if (s[n - 1] == 'o') { //n-1番目の証言があってるかチェック
		if (a[n - 1] && a[n - 2] != a[0])return false;
		else if (!a[n - 1] && a[n - 2] == a[0])return false;
	}
	else {
		if (a[n - 1] && a[n - 2] == a[0])return false;
		else if (!a[n - 1] && a[n - 2] != a[0])return false;
	}

	if (s[0] == 'o') { //上と同様に0番目の証言があってるかチェック
		if (a[0] && a[n - 1] != a[1])return false;
		else if (!a[0] && a[n - 1] == a[1])return false;
	}
	else {
		if (a[0] && a[n - 1] == a[1])return false;
		else if (!a[0] && a[n - 1] != a[1])return false;
	}

	for (int i = 0; i < n; i++) {
		if(a[i]==Sheep)cout << 'S';
		else cout << 'W';
	}
	cout << endl;
	return true;
}

int main() {

	cin >> n >> s;
	for (int x = 1; x >= 0; x--) {
		for (int y = 1; y >= 0; y--) {
			if (func(x, y))return 0;
		}
	}
	if (func(Sheep, Sheep))return 0;
	if (func(Sheep, Wolf))return 0;
	if (func(Wolf, Sheep))return 0;
	if (func(Wolf, Wolf))return 0;

	cout << -1 << endl;
	return 0;
}