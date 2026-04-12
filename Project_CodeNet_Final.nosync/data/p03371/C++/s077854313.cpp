#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int main(){
  long long a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  long long ans = a*x+b*y;
  ans = min(ans, (2LL*c*x) + max(0LL,y-x)*b);
  ans = min(ans, (2LL*c*y) + max(0LL,x-y)*a);
  cout<<ans<<endl;
  return 0;
}
