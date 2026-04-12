#include<iostream>
#include <string>
using namespace std;

int main() {
	int x;
	cin >> x;
	string result = (x==7 || x==5 || x==3) ? "YES" : "NO";
	
	cout << result << endl;
}