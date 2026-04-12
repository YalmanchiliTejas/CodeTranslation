#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int x, y, z;
	cin >> x >> y >> z;
	int i=1;
	while(1){
		if(y*i + z*(i+1) > x) break;
		i++;
	}
	cout << i-1 << endl;
	
	return 0;
}