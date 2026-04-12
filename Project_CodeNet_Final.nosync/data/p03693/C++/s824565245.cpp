#include <bits/stdc++.h>
using namespace std;
 int main() {
   int r,g,b;
   cin >> r >>b>>g;
   if(b==0 && g==0) cout << "YES" << endl;
   else if((b*10+g)%4==0) cout <<"YES" << endl;
   else cout <<"NO"<<endl; 
 }