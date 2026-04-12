#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
  int a,b,c,x,y ;
  cin >> a>>b>>c>>x>>y ;
  
  if(a+b<2*c){
    cout << a*x+b*y << endl;
  }else{
    if(x<y){
      int ans1 = 2*c*y ;
      int ans2 = 2*c*x + (y-x)*b ;
      if(ans1<ans2)
        cout << ans1 << endl;
      else
        cout << ans2 << endl;        
  }else{
      int ans3 = 2*c*x ;
      int ans4 = 2*c*y + (x-y)*a ;
      if(ans3<ans4)
        cout << ans3 << endl;
      else
        cout << ans4 << endl;        
    }
  }
    return 0;
}
