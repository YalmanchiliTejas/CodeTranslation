#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,a,b,c;
  int64_t ans=10000000000000;
  cin >> a >> b >> c >> x >> y;
  for(int i=0;i<=100000;i++){
    int k=c*2*i+a*max(0,x-i)+b*max(0,y-i);
    if(k<ans)ans=k;
  }
  cout << ans << endl;
}
    
