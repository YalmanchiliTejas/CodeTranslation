#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int X,Y,Z;
	cin >> X >> Y >> Z;
	X = X - Z;
	int rslt = 0;
	rslt = X / (Y + Z);
	cout << rslt << endl;
	
}