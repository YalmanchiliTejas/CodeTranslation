//abc095_c.cpp
//Sat Apr 21 20:19:03 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
	int a;
	int b;
	int c;
	int x;
	int y;
	cin >> a >> b >> c >> x >> y;

	int cost = 0;

	if (a+b > 2*c){
		if (x>y){
			cost = 2*x*c;
		}else if (x<=y){
			cost = 2*y*c;
		}
	}else {
		cost = a*x + b*y;
	}

	int min = 0;
	int costtemp = 0;
	if (x>y){
		min = y;
	}else if (x<=y){
		min = x;
	}
	costtemp = min * c * 2 + (x-min)*a + (y-min)*b;

	if (costtemp < cost){
		cost = costtemp;
	}

	cout << cost << endl;
}