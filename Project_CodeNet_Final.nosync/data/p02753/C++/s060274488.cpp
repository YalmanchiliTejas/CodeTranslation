#include<bits/stdc++.h>
using namespace std;

string S;

int main(){
	cin >> S;
	set<char> tmp;
	for(long long i = 0; i < S.size(); i++) {
		tmp.insert(S[i]);
	}
	if(tmp.size() == 2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}
