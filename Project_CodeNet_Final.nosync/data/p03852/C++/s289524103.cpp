#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

#define rep(i, n) for(int i=0;i<n;i++)

using namespace std;
int main(){
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;

	return 0;
}