#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 100*a + 10*b + c;
	string res = (ans%4 == 0)?"YES":"NO";
	cout << res << endl;
}