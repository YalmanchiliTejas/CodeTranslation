#include <iostream>

using namespace std;

int x, y, z, nr;

int main(){

         cin>>x>>y>>z;

         nr=0;

         x -= z;
         while ( x > 0){
                  x -= y+z;
                  if( x >= 0)
                           nr++;
         }

         cout<<nr;

return 0;
}
