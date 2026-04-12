#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int Min=2000000000; 
  rep(i,max(x,y)*2+1){
    int ca=max(0,x-i/2),cb=max(0,y-i/2);
    int cost=ca*a+cb*b+i*c;
    Min = min(Min,cost);  
  }
  cout << Min << endl;
}
