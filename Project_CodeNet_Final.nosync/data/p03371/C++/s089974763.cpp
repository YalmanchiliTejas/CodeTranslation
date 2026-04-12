#include<bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,C,X,Y,a=0;
  cin >> A >> B >> C >> X >> Y;
  long long ans=2000000000;
  for(int i=0;i<=2*max(X,Y);i+=2){
    ans=min(ans,i*C+A*max(a,X-i/2)+B*max(a,Y-i/2));
  }
  cout << ans << endl;
}