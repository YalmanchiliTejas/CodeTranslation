#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

ll n,k,m,a,b,c,x,y;
string s;

int main() {
  cin >> a >> b >> c >> x >> y;
  if(c*2<=a+b){
    if(x>y)
      cout << min(y*2*c+(x-y)*a,2*x*c) << endl;
    else 
      cout << min(x*2*c+(y-x)*b,2*y*c) << endl;
  }else 
      cout << a*x+b*y << endl;
}