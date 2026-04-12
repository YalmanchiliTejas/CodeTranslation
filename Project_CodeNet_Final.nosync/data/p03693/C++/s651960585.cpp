#include <bits/stdc++.h>
using namespace std;

int main() {
 char a,b,c;
 cin >> a >> b >> c ;
 string s = "AAA";
 s.at(0)=a;
 s.at(1)=b;
 s.at(2)=c;
  
 int x=stoi(s);
 if(x%4==0)
   cout <<"YES";
  else 
    cout << "NO";
 
}
