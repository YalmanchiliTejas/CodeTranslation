#include <bits/stdc++.h>
using namespace std;
                                                                                   

int main(){
                                                                     

    string s;

    int i;

    
    cin >> s;


    for( i = 0 ; i < s.size() - 1 ; i = i + 1 ){

         if( s.substr(i, 2) == "AC" ){

             cout << "Yes" << endl;

             return 0;

             }

         }


    cout << "No" << endl;


    return 0;

    }