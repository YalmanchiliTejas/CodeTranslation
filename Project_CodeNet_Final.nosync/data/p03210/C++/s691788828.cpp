#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){

	int X;
	string ans = "NO";

	cin >> X;

	ans = (X == 3 || X == 5 || X == 7) ? "YES" : ans;

	cout << ans << endl;

}