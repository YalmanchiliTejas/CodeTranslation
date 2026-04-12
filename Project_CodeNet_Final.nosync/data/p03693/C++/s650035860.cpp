#include<iostream>
#include<string>

using namespace std;

int main() {
	string a, b, c, d;
	int ans;
	cin >> a >> b >> c;
	d = a + b + c;
	//string型からint型へ直接変換
	ans = stoi(d);
	if (ans % 4 == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}

	return 0;
}