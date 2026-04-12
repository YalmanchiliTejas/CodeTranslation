#include <bits/stdc++.h> 
using namespace std;
int main(){
	int a, b, c, n;
	cin >> a >> b >> c;
	a *= 100;
	b *= 10;
	n = a + b + c;
	if(n % 4 == 0)cout << "YES" << endl;
	else if(n % 4 != 0)cout << "NO" << endl;
	return 0;
 
}