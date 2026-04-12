#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

int a,b,c,x,y;
int sum(int d,int e,int f){
  return a*d + b*e + c*f;
}

int main(){
  cin >> a >> b >> c >> x >> y;
  if(a+b <= 2*c){
    cout << sum(x,y,0) << endl;
    return 0;
  }
  int piza1 = sum(0,0,2*max(x,y));
  int m = min(x,y);
  int piza2 = sum(x-m,y-m,2*m);
  int ret = min(piza1,piza2);
  cout << ret << endl;
  return 0;
}
