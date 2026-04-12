#include<iostream>
using namespace std;
int main()
{
	string s,ans;
	cin >> s;
	if (s=="AAA" || s=="BBB"){
		ans="No";
	}else{
		ans="Yes";
	}
	cout << ans << endl;
	return 0;
}