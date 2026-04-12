#include <iostream>
#include <string>
using namespace std;

int N(), E(), S(), W(), R(), L(), a[6], tmp;

int N(){
	tmp = a[0];
	a[0] = a[1];
	a[1] = a[5];
	a[5] = a[3];
	a[3] = tmp;
	return 0;
}
int E() {
	tmp = a[0];
	a[0] = a[4];
	a[4] = a[5];
	a[5] = a[2];
	a[2] = tmp;
	return 0;
}
int W() {
	tmp = a[0];
	a[0] = a[2];
	a[2] = a[5];
	a[5] = a[4];
	a[4] = tmp;
	return 0;
}
int S() {
	tmp = a[0];
	a[0] = a[3];
	a[3] = a[5];
	a[5] = a[1];
	a[1] = tmp;
	return 0;
}
int R() {
	tmp = a[1];
	a[1] = a[2];
	a[2] = a[3];
	a[3] = a[4];
	a[4] = tmp;
	return 0;
}
int L() {
	tmp = a[1];
	a[1] = a[4];
	a[4] = a[3];
	a[3] = a[2];
	a[2] = tmp;
	return 0;
}

int main(){
	int n, ans, k;
	string input;
	while(cin>>n){
		if (n == 0 ){break; }
		ans = 1;
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		a[3] = 5;
		a[4] = 4;
		a[5] = 6;
		for (int i = 0; i < n; i++) {
			cin >> input;
			k = input[0];
			if (k == 78) { N(); }
			else if (k == 83) { S(); }
			else if (k == 69) { E(); }
			else if (k == 87) { W(); }
			else if (k == 82) { R(); }
			else if (k == 76) { L(); }
			ans += a[0];
		}
		cout << ans << endl;

	}
}