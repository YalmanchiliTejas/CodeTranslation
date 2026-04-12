#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin >> s;
  	bool f1 , f2;
  	f1 = f2 = false;
  	if(s[0] == 'A' || s[1] == 'A' || s[2] == 'A')
      	f1 = true;
  	if(s[0] == 'B' || s[1] == 'B' || s[2] == 'B')
      	f2 = true;
  	if(f1 and f2)
      	cout << "Yes";
 	else
      	cout << "No";
  	return 0;
}