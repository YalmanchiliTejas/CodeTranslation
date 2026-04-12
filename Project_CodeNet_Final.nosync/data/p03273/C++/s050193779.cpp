#include <bits/stdc++.h>
using namespace std;
 int main(){
   int H,W;
   cin >> H >> W;
   vector<vector<char>>s(H,vector<char>(W));
  for(int i = 0 ; H > i ; i++ ){
    for( int j = 0 ; W > j ; j++ ){
      cin >> s.at(i).at(j);
    }
  }
   
 
   vector<bool>row(H,false);
   vector<bool>col(W,false);
   for( int i = 0 ; H > i ; i++){
     for(int j =0 ; W > j ; j++){
       if( s.at(i).at(j) == '#' ){
         row.at(i) = true;
         col.at(j) = true;
       }
     }
   }
   for( int i = 0 ; H > i ; i++){
     if( row.at(i) ){
       for( int j = 0 ; W > j ; j++){
         if ( col.at(j) ){
           cout << s.at(i).at(j);
         }
       }
        cout << endl;
     }
       
        }

 }