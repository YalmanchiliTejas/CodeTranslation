#include<iostream>
using namespace std;
int main(){
  int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
  int max_v = (max(x,y)==x) ? a : b; // 枚数が多い方のピザの価格
  long long ans=0;
  if((a+b)<=2*c){
    cout << a*x+b*y << endl;
  }else{
    if(max_v>=2*c) cout << c*2*max(x,y) << endl;
    else{
      cout << c*2*min(x,y) + max_v*(max(x,y)-min(x,y)) << endl;
    }
  }
  return 0;
}