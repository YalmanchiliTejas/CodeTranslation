//abc078_b.cpp
//Sat Feb 24 17:34:13 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
	int x;
	int y;
	int z;
	cin >> x;
	cin >> y;
	cin >> z;

	int answer = (x-z)/(y+z);

	cout << answer << endl;
}