#include <iostream>
#include <string>

using namespace std;
string s, ans[4];
int n;

int index(string a, char b) {//この関数は文字列が存在しない場合は考えない　　bは次に追加する文字の判定
	int res;
	if (a[a.length() - 1] == 'S') {//ここが違う
		if (b == 'o') {
			if (a[a.length() - 2] == 'S')res = 0;  //ss
			else res = 1;                          //sw
		}
		else {
			if (a[a.length() - 2] == 'S')res = 1;  //sw
			else res = 0;                          //ss 
		}
	}
	else {
		if (b == 'o') {
			if (a[a.length() - 2] == 'S')res = 3;  //ww
			else res = 2;                          //ws
		}
		else {
			if (a[a.length() - 2] == 'S')res = 2;  //ws
			else res = 3;                          //ww 
		}
	}
	return res;
}

char nextC(int index) {
	if (index % 2 == 0) {//0
		return 'S';
	}
	else {
		return 'W';
	}
}

bool cond(string a, int index) {//indexは0,length()-1だけ
	bool flag = false;
	if (a == "-1")return flag;
	if (index == 0) {
		if (s[s.length() - 1] == 'o') {
			if (a[a.length() - 1] == 'S') {
				if (a[a.length() - 2] == a[0])flag = true;
			}
			else if (a[a.length() - 2] != a[0])flag = true;
		}
		else {
			if (a[a.length() - 1] == 'S') {
				if (a[a.length() - 2] != a[0])flag = true;
			}
			else if (a[a.length() - 2] == a[0])flag = true;
		}
	}
	else if(index == 1){
		if (s[0] == 'o') {
			if (a[0] == 'S') {
				if (a[a.length() - 1] == a[1])flag = true;
			}
			else if (a[a.length() - 1] != a[1])flag = true;
		}
		else {
			if (a[0] == 'S') {
				if (a[a.length() - 1] != a[1])flag = true;
			}
			else if (a[a.length() - 1] == a[1])flag = true;
		}
	}
	return flag;
}

int main() {
	cin >> n >> s;

	ans[0] = "SS"; ans[1] = "SW";  ans[2] = "WS"; ans[3] = "WW";
	for (int i = 1; i < s.length()-1; i++) {
		for (int j = 0; j < 4; j++) {
			//cout << ans[j] << endl;
			ans[j] += nextC(index(ans[j], s[i]));
		}
	}

	for (int i = 0; i < 4; i++) {
		if (cond(ans[i], 0) && cond(ans[i], 1)) {
			cout << ans[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}