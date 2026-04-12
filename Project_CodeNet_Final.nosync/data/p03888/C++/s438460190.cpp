#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  

	double a, b; cin >> a >> b;
	cout << setprecision(20) << a * b / (a + b) << endl;	
	return 0;	
}