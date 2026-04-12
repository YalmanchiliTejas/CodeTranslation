#include <bits/stdc++.h>
using namespace std ;

int main()
{ 
  int x, y, z ;
  cin >> x >> y >> z ;
  int64_t calcu = 0 ;
  int count = 0 ;
  while(calcu + z + y < x)
  {
    
    calcu += z + y ;
    if(calcu + z > x)
    {
      break ;
    }
    //cout << calcu << endl ;
    count++ ;
  }
  cout << count << endl ;
}
