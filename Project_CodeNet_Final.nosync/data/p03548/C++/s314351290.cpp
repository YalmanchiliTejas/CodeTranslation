#include <bits/stdc++.h>
using namespace std;
int main(){
 int X,Y,Z,ans = 0;
 cin >> X >> Y >> Z;
 int sennyuu = Y + Z;
 X = X-Z;
 ans = X /sennyuu;
 printf("%d\n",ans);
}