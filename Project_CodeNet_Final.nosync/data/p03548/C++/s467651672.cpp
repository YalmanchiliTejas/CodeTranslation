#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
   int x,y,z;

   cin >> x >> y >> z;

   int ans;

   ans = (x-z) / (y+z);
   cout << ans << endl;
   return 0;
}