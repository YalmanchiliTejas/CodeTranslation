#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b,c,x,y;
int main(void){
  while(cin >> n >> a >> b >> c >> x && n){
    int t = 0;
    for(int i = 0; i < n; i++){
      cin >> y;
      while(y != x && t <= 10000){
	x = (a*x+b)%c;
	t++;
      }
      x = (a*x+b)%c;
      t++;
    }
    t--;
    if(t > 10000) cout << -1 << endl;
    else cout << t << endl;
  }
}