#include<iostream>
using namespace std;

int main() {
	int R, G, B;
	cin >> R >> G >> B;
	if (((G%2)*2+B)%4) cout << "NO";
	else cout << "YES";
	return 0;
}