#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
using namespace std;
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007

ll a,b,c,x,y,ans;
int main(int argc, char const *argv[]) {
  std::cin >> a >> b >> c >> x >> y;
  if(a+b<c*2){
    std::cout << x*a+b*y << '\n';
    return 0;
  }
  else{
    ans=min(x,y)*2*c;
    if(x>y) ans+=min(a,2*c)*(x-y);
    else ans+=min(b,c*2)*(y-x);
    std::cout << ans << '\n';
  }
      
  return 0;
}
