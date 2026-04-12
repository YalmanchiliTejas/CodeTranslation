#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int comp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main() {
	int x;
	cin >> x;
	if(x == 7 || x == 5 || x == 3)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}