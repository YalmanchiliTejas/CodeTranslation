#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,y,z, i; 
	cin >> x >> y >> z;

	for( i = 0; i*(y+z)+z <= x; i++);
	cout << i-1 << endl;
	return 0;
}

