#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;

  ll result = a*x + b*y;

  ll cxy = min(x,y);
  result = min(result, cxy*2*c + (x-cxy)*a + (y-cxy)*b);

  ll ac = max(x,y);
  result = min(result, (ac*2*c));

  cout<<result;

  return 0;
}