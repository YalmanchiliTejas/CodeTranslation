#include <iostream>
using namespace std;
int main(void)
{ 
    int x,y,z;
   cin >> x >> y >> z;
   int ans = 0;
   for(size_t i = 0 ;  ; i++)
   {
      int l =(i * y) + ((i+1) * z);
      if(l <= x)
        ans = i;
     else
       break;
   }
  cout << ans << endl;
  return 0;
}