#include <iostream>
#include <string>
using namespace std;
 
int main() {
	// your code goes here
	string S;
	cin >>S;
	int flag =0;
	for(int i=0; i<S.length()-1;i++){
		if(S[i]=='A' && S[i+1]=='C'){flag=1;}
	}
	if(flag==1)cout <<"Yes" << endl;
	else cout<< "No" << endl;
	return 0;
}