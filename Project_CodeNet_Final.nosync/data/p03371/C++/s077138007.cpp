#include<iostream>

using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  if(a+b<=2*c){
    cout << a*x + b*y << endl;
  }
  else{
    int ans=0, mn=min(x, y);
    ans += c*2*mn;
    x -= mn;
    y-=mn;
    ans += x*min(a, 2*c) + y*min(b,2*c);
    cout << ans << endl;
  }
}