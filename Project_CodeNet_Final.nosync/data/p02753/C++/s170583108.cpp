#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
	string s;
  	cin >> s;
  	for(long i = 0; i<3; i++){
      if(s[i]==s[i+1] && s[i+1]==s[i+2]){
        cout << "No" << endl;
        break;
      }
      else if(s[i]!=s[i+1]){
        cout << "Yes" << endl;
        break;
      }
    }
}