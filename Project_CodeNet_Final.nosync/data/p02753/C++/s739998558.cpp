#include<bits/stdc++.h>
using namespace std;

int main(void){
  string s;
  cin >> s;
  int a = 0, b = 0;
  for(int i = 0; i < 3; i++){
    if(s[i]=='A')	a++;
    if(s[i]=='B')	b++;
  }
  if(a && b)	cout << "Yes";
  else	cout << "No";
}