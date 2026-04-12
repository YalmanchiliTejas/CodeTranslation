#include<bits/stdc++.h>
using namespace std;

string S;

int main(){
	cin >> S;
	for(int i = 0; i < S.size() - 1; i++){
		if(S[i] == 'A' && S[i + 1] == 'C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
			cout << "No" << endl;
			return 0;





}
