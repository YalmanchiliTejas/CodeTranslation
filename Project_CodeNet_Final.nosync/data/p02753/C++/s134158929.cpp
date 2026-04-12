#include <bits/stdc++.h>
using namespace std;
 
int main(){
  	string S;
 
  	cin >> S;
  	for (int i = 1; i < 3; i++) {
      if (S[0] != S[i]) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  
	
    cout << "No" << endl;
    return 0;
}