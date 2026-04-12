#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	string r,g,b;
	cin>>r>>g>>b;
	int n = stoi(r+g+b);
	if(n%4==0)cout << "YES" << endl;
	else cout << "NO" << endl;
}
