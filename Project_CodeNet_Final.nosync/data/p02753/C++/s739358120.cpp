#include<bits/stdc++.h>
using namespace std;

int main(){
  char s[3];
  int a=0,b=0;
  for(int i = 0;i < 3;i++){
    cin >> s[i];
    if(s[i] == 'A')
      a++;
    if(s[i] == 'B')
      b++;
  }

  if(a == 3 || b == 3)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
