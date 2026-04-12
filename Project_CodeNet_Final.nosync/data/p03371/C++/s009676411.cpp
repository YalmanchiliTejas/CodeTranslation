    #include <iostream>
    #include <stdio.h>
    #include <string>
    #include <math.h>
    #include<algorithm>
    #include <numeric>
    using namespace std;
 
    int main(){
      int A,B,C,X,Y;
      cin >> A >> B >> C >> X >> Y;
      long long ans=A*X+B*Y;
      if(X>=Y){
       for(long long i=Y;i<=X;i++){
         ans=min(ans,2*i*C+(X-i)*A);
       }
      }
      else{
       for(long long i=X;i<=Y;i++){
        ans=min(ans,2*i*C+(Y-i)*B); 
       }
      }
      cout << ans << endl;
      return 0;}