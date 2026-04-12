#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	
	int n; cin >> n;
	if(n == 3 || n == 5 || n == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;	
}
