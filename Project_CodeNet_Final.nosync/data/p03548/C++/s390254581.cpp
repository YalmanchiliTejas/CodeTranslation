#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int X,Y,Z;
    cin >> X>>Y>>Z;
    int ans = 0;
   for(int i = 1;i < X+1;i++){
       if((X - Z) - (Y+Z)*i >= 0) ans++;
       else break;
   }
   cout << ans << endl;
}