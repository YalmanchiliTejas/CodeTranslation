#include <bits/stdc++.h>

using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	char ch;
	t = 1;
	while(t--) {
	 cin >> ch;
	 if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
	  cout << "vowel" << endl;
	 else
	  cout << "consonant" << endl;
	}
	return 0;
}

