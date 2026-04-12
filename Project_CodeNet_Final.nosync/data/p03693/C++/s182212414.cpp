#include <bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,a;
  cin>>r>>g>>b;
  a=g*10+b;
  if (a%4==0) printf ("YES");
  else printf ("NO");
  return 0;
}
