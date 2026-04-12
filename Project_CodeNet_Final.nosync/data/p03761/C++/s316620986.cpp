#include <bits/stdc++.h>
using namespace std;
                                                                                                
  

int main(){
                                                                     

    int n, i, j, t;

    string a = "abcdefghijklmnopqrstuvwxyz";

    vector<int> an(26);

    string k;


    cin >> n;

    vector<string> s(n);

    for( i = 0 ; i < n ; i = i + 1 ){

         cin >> s.at(i);

         }


    for( i = 0 ; i < n ; i = i + 1 ){

         for( j = 0 ; j < 26 ; j = j + 1 ){

              if( i == 0 ) an.at(j) = count(s[i].begin(), s[i].end(), a.at(j) );

              else{ 

                     t = count(s[i].begin(), s[i].end(), a.at(j) );

                     if( t < an.at(j) ) an.at(j) = t;

                     }

              }

         }

    
    for( i = 0 ; i < 26 ; i = i + 1 ){

         for( j = 0 ; j < an.at(i) ; j = j + 1 ){

              k.push_back( a.at(i) );

              }

         }


    cout << k << endl;

    return 0;

    }