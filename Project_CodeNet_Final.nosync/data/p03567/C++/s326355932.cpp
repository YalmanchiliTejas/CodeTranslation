#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
	string S;
	
	getline(cin, S);
	int i, benar = 0;
	for (i=1; i<S.length(); i++){
		if (S[i] == 'C' && S[i-1] == 'A'){
			benar = 1;
			break;
		}
	}

	if (benar)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}