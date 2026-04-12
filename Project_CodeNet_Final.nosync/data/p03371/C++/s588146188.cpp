#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  if(a+b<=2*c){
    cout << a*x + b * y  << endl;
  }
  else {
    int abc = c *2 * min(x,y) + max(b*(y-x),a*(x-y));
    int ccc = c *2 * max(x,y);
    cout << min(abc, ccc)  << endl;
  }
}
