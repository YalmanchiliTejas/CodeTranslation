#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int a,b,c,x,y;
  cin >> a>>b>>c>>x>>y;
  int mini=1e9;
  rep(i,max(x,y)+1){
    int z=x,w=y;
    int ans=0;
    ans+=2*c*i;
    z-=i;
    w-=i;
    if(z>=0){
    ans+=z*a;
    }
    if(w>=0){
    ans+=w*b;
    }
    mini=min(mini,ans);
  }
  cout << mini;
}