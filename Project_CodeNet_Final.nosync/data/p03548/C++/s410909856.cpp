#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
	int x,y,z;
	cin >> x >> y >> z;
	x-=z;
	int ans=0;
	for(int i=0; ; i++){
		if(i*(y+z)<=x)ans=i;
		else break;
	}
	cout << ans << endl;
	return 0;
}