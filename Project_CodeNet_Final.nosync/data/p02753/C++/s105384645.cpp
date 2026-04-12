#include <iostream>
#include <string>
using namespace std;
int main(){
	string S;
  	int A=0,B=0;
  	cin >> S;
  	for(int i=0;i<3;i++){
    	if(S[i]=='A') A=1;
      	else if(S[i]=='B') B=1;
    }
  	if(A and B ==1) cout << "Yes" << endl;
  	else cout << "No" << endl;
}