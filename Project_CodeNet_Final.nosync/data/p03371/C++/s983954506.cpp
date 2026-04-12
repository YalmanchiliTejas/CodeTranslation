#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int z=0;
  if(a+b>2*c){
    int w=min(x,y);
    z=2*w;
    x-=w;
    y-=w;
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(x>0 && a>2*c){
      z+=2*x;
      x=0;
    }
    else if(y>0 && b>2*c){
      z+=2*y;
      y=0;
    }
  }
  //cout<<x<<" "<<y<<" "<<z<<endl;
  cout<<a*x+b*y+c*z<<endl;
}
