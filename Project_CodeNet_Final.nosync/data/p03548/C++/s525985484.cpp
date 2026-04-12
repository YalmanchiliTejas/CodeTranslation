#include <bits/stdc++.h>
using namespace std;

int main(void){
	int x, y, z, people = 0;
	cin >> x >> y >> z;
	for (int i = 1; i < 100000; ++i){
		if (i*y + (i+1)*z > x){
			break;
		}
		people++;
	}
	cout << people << endl;
	return 0;
}