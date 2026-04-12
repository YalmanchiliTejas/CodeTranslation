#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z;
	cin >> x >> y >> z;
	int res = (100*x+10*y+z);
	if(res % 4) cout << "NO" << endl;
	else cout << "YES" << endl;
}