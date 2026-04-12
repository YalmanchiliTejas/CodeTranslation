#include <bits/stdc++.h>
using namespace std;

int main() {
string S;
  cin >> S;
  int count = 0;
  for(int i = 0; i < S.length(); i++){
  	if(S[0] != S[i]){
    	count ++;
    }
  }
  if(count == 0){
  	cout << "No" << endl;
  }
  else cout << "Yes" << endl;
}