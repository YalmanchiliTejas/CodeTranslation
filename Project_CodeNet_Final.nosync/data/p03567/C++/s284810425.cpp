#include <iostream>
#include <string>
using namespace std;

int main() {
	string S; cin >> S;
	bool p=false;
	for(int i=0; i+1<S.size(); ++i){
	    if(S[i]=='A' && S[i+1]=='C'){
	        p=true;
	        break;
	    }
	}
	if(p) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
