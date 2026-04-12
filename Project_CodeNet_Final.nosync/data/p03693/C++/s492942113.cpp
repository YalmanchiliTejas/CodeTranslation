#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b,c;
  cin >> a >> b >> c;
  int total = 100*a + 10*b +c;
  string s ="NO";
  if(total%4==0)  s="YES";
  
  cout << s << endl;
}