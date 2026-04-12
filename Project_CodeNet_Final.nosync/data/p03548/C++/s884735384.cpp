#include <iostream>

using namespace std;

int main()
{
   int x, y, z; cin >> x >> y >> z;

   int max = 0;
   while(x >= y + 2 * z){
       x -= y + z;
       max++;
   }
   cout << max << endl;
}