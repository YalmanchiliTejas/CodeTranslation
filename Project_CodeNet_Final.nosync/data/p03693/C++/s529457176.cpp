//abc064_a.cpp
//Sun Sep 30 18:14:47 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int r,g,b;
	cin >> r >> g >> b;

	if ((r*100+g*10+b)%4 == 0){
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
}