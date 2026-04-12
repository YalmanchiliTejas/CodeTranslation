#include <iostream>
using namespace std;

int main(void){
	int a, b, c;
	cin >> a >> b >> c;
	int cnt = c + b*10 + a*100;
	if(cnt % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}