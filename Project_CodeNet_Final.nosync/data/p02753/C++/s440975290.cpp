#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
 int i,a;
 a=0;
 string s;
 cin >> s;
 for(i=0;i<3;i++)
 {
  if(s[i]=='A')
  a++;
 }
 if(a!=0 && (3-a)!=0)
 cout << "Yes";
 else
 cout << "No";
 return 0;
}