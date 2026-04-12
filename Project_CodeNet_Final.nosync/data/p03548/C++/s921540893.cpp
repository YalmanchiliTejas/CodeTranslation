#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cstdlib>

using namespace std;

int main(){

	int x, y, z, count=0, pepole=0;
	cin >> x >> y >> z;
	x = x - z;
	y = y + z;
	while(count <= x){
		count += y;
		pepole++;
	}
	cout << pepole-1 << endl;

	return 0;
}
