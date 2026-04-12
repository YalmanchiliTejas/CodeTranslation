#include <iostream>
#include <string>

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int r,g,b;
	cin >> r >> g >> b;
	int x = 100*r + 10*g + b;
	if(x % 4 == 0) cout << "YES";
	else cout << "NO";
}