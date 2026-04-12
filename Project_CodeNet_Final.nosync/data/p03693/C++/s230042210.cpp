#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <new>
#include <map>

using namespace std;
 
int main() {
	int r,g,b,val,ans;
	cin >> r >> g >> b;
	val = 100*r+g*10+b;
	ans = val % 4;
	if(ans == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}