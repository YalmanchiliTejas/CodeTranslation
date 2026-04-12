#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  for(int i = 0; i < S.length(); i++){
  	if(S.at(i) == 'A'){
    	if(S.at(i+1) == 'C' && i+1 != S.length()){
        	cout << "Yes" << endl;
          	break;
        }
    }
    if(i == S.length() - 1){
    	cout << "No" << endl;
    }
  }
  
}