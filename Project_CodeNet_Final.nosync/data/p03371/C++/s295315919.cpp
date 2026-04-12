#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
  long long a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  long long cost = (x+y)*max(a,b);
  long long xi,yi,costi;
  long long k = 0;
  for(int i=0;i<100001;i++){
    xi = x;
    yi = y;
    costi = 2*c*i;
    xi -= i;
    yi -= i;
    if(xi >= 0 || yi >= 0) costi += a*max(k,xi)+b*max(k,yi);
    else break;
    cost = min(cost,costi);
  }
  cout << cost << endl;
  return 0;
}
