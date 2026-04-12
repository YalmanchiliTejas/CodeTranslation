#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	int n,x,y;
	cin >> n;
	x = n * 800;
	y = x / (800*15) * 200;
	cout << x - y << endl;
}