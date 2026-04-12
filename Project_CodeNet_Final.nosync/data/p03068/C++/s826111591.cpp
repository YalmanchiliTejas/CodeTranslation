#include <bits/stdc++.h>
using namespace std;
int main (){
   int n , k ;
   cin >>n ;
   string s ;
   cin >> s ;
   cin >> k;
   char mezirusi;
   mezirusi = s.at(k-1);
  
   for ( int i= 0 ; i < s.size() ; i++){
     if(s.at(i) != mezirusi ){
       s.at(i) = '*';
       }
       }
       cout << s << endl;
       }