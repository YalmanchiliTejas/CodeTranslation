#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	
	int r, g, b;
	
	cin >> r >> g >> b;
	
	int hoge = r * 100 + g * 10 + b;
	
	if(hoge % 4 == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	
	return 0;
}