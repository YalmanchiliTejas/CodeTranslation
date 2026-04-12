#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
  //ABを2i枚→AをX-i枚、BをY-i枚
  int mincost=1e12;
  for(int i=0; i<=max(X,Y); i++){
    mincost=min(mincost,A*max(0,X-i)+B*max(0,Y-i)+C*2*i);
  }
  cout << mincost << endl;
}