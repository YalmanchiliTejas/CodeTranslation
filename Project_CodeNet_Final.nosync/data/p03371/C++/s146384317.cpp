#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int doub;
  if(a+b>=2*c)doub=2*c;
  else doub=a+b;
  if(a>=2*c && x>=y) cout << doub*y+ (x-y)*2*c <<endl;
  else if(b>=2*c && y>=x) cout << doub*x+(y-x)*2*c <<endl;
  else if(x >=y) cout << doub*y+(x-y)*a << endl;
  else cout << doub*x+(y-x)*b << endl;
    
  
}
