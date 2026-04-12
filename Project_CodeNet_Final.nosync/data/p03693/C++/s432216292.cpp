#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int r;
	int g;
	int b;
	cin >> r >> g >> b;
	int ans = r * 100 + g * 10 + b ;
	if(ans%4 == 0) cout <<"YES" << endl;
	else cout << "NO" << endl;
}
