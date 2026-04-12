#include <bits/stdc++.h>
using namespace std;

int main() {
  	string r, g, b;
	cin >> r >> g >> b;
  	int num = atoi((r + g + b).c_str());
  	if(num % 4 == 0){
    	cout << "YES" << endl;
    }else{
    	cout << "NO" << endl;
    }
}