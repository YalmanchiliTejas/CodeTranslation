#include<bits/stdc++.h>
using namespace std;
int main(){
  char str[10];
  cin >> str;
  if(strstr(str,"AC")!='\0')
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}