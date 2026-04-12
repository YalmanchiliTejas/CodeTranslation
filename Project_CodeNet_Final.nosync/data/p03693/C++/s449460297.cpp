#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int comp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main() {
	string r, g, b, ans;
	int answ;
	cin >> r >> g >> b;
	ans = g + b;
	answ = atoi(ans.c_str());
	if(answ % 4 == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}