#include <iostream>

using namespace std;

string s;
int nA, nB;

int main() {
	cin>>s;
	for (int i=0; i<3; i++) {
		if (s[i]=='A') nA++;
		if (s[i]=='B') nB++;
	}
	if (nA>=1 && nB>=1) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	cout<<'\n';
}