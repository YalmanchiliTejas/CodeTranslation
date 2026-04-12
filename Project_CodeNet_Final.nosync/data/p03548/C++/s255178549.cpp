#include <bits/stdc++.h>
using namespace std;
                                                                                   


int main(){
                                                                     

    int x, y, z, i;


    cin >> x >> y >> z;


    for( i = 1 ;  ; i = i + 1 ){

         if( z + y + z + ( i - 1 ) * ( y + z ) > x ) break;

         }


    cout << i - 1 << endl;
    

    return 0;

    }