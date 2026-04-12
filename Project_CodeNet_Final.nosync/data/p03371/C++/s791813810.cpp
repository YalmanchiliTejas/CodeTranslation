#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans = a*x+b*y;
  for(int i=0;i<=max(x,y);i++){
    int ab=i*2;
    int abc=ab*c+a*max(0,x-i)+b*max(0,y-i);
    ans=min(ans,abc);
  }
  cout<< ans << endl;
  return 0;
}
    