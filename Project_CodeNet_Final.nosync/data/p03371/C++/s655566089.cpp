#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
                                                                                                
  
int main(){
                                                                                                
   
    int a, b, c, x, y, i, k;

    int m = 1000000000; 

    
    cin >> a >> b >> c >> x >> y;


    for( i = 0 ; i <= 200000 ; i = i + 1 ){

         k = 2 * c * i + a * max( x - i, 0 ) + b * max( y - i, 0 );

         if( m > k ) m = k;

         }

    cout << m << endl;

    return 0;

}