#include<bits/stdc++.h>
using namespace std;

int main() {
	int r,g,b;
  	cin >> r >> g >> b;
  
  	int bottom2 = g * 10 + b;
  
  	if(bottom2 % 4 == 0) {
    	cout << "YES" << endl;
    }else {
    	cout << "NO" << endl;
    }
}