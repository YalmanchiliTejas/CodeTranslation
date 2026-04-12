#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	if((a*100+b*10+c)%4==0)
		cout << "YES\n";
	else
		cout << "NO\n";


	return 0;
}