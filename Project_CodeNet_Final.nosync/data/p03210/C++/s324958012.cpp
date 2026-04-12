#include <iostream>
#include <string>
using namespace std;

int main(){
	int a;
  	cin >> a;
  	string ans;
  	if(a%2 != 0 && a != 1 && a != 9) ans = "YES";
  	else ans = "NO";
  	cout << ans << endl;
}