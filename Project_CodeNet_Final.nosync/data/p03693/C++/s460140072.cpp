#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	int r, g, b;
	cin >> r >> g >> b;
	r = g*10 + b;
	if(r % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}