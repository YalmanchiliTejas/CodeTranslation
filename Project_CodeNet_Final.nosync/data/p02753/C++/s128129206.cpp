#include <iostream>
using namespace std;

int main() {
    string S;
  	string s;
    cin >> S;
    if(S[0]==S[1]){
    	if(S[0]==S[2])  cout << "No" << endl;
    	else cout << "Yes" << endl;
    } 
    else cout << "Yes" << endl;
}