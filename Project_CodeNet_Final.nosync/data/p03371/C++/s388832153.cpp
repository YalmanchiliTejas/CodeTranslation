#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;
int main(void) {
  long long int a, b, c, x, y;
  cin>>a>>b>>c>>x>>y;
  long long int ans=0;

  if(2*c<a+b) {
    ans+=min(x, y)*2*c;
    if(x>y) {
      ans+=min(2*c, a)*(x-y);
    } else
      {
	ans+=min(2*c, b)*(y-x);
      }
    }
  else {
    ans+=a*x+b*y;
  }
  cout<<ans<<endl;
  return 0;
}
