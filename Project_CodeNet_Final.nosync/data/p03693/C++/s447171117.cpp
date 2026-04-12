#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
	int r,g,b;
	cin >> r>>g>>b;
	if ((r * 100 + g * 10 + b) % 4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
