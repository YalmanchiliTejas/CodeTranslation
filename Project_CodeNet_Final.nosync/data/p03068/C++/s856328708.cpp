#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;

	char sk;
	sk = s[k-1];

	string out_s(n, '*');

	for(int i=0;i<n;++i){
		if(sk == s[i]) out_s[i]=sk;
	}

	cout << out_s << endl;

}
