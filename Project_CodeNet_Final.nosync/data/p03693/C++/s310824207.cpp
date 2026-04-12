#include <bits/stdc++.h>
using namespace std;

int main(void){
	int r, g, b;
	cin >> r >> g >> b;
	int product =  10 * g + b;
    if(product % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}