#include<iostream>
#include<string>
using namespace std;
int main() {
	int a;
	int b;
	int c;
	int d;
	int e;
	std::cin >> a >> b >> c;
	if ((a*100+b*10+c*1) % 4 == 0) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	
	std::cin >> e;
}