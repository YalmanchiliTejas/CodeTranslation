#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int a,b,c,x,y;
  cin >>a>>b>>c>>x>>y;
  int sum=1000000000;
  
for (int i = 0; i <=max(x,y); ++i){
      int j=max(x-i,0);
      int k=max(y-i,0);
      int ans =a*j+b*k+2*c*i;
     sum=min(sum,ans);
     }
    
  cout << sum <<endl;

}
