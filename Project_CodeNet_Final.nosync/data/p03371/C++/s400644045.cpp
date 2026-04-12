#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  unsigned long long cnt=0;
  int sa=0;
  cin >> a >> b >> c >> x >> y;
  if(x-y>0) sa=x-y;
  else sa=y-x;
  if(c*2<a+b){
    if(a<c*2&&x>y) {
      cnt+=sa*a;
      x-=sa;
    }
    if(b<c*2&&y>x) {
      cnt+=sa*b;
      y-=sa;
    }
    for(int i=0;true;i++){
      cnt+=c*2;
      y--;
      x--;
      if(x<=0&&y<=0) break;
    }
    cout << cnt << endl;
  }
  else {
    if(x>y) {
      cnt+=sa*a;
      x-=sa;
    }
    if(y>x) {
      cnt+=sa*b;
      y-=sa;
    }
    for(int i=0;true;i++){
      cnt+=a;
      cnt+=b;
      y--;
      x--;
      if(x<=0&&y<=0) break;
    }
    cout << cnt << endl;
  }
}