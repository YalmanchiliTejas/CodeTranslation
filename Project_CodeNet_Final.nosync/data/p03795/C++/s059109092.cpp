#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	int n;
	cin >> n;
	cout << (800 * n) - ((n / 15) * 200)<< endl;
	return 0;
}