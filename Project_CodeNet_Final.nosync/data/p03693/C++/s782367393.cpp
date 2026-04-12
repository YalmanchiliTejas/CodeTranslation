#include<iostream>
#include <string>
using namespace std;

int main() {
	int r, g, b;
	 cin >> r >> g >> b;
	 int s = 10 * g + b;
	 if (s % 4)cout << "NO";
	 else cout << "YES";
}