#include <bits/stdc++.h>
using namespace std;

#define rep(ver,n) rep2(ver,0,n)
#define rep2(ver,m,n) for(int ver=m;ver<(n);ver++)
#define loop while(true)
#define dup(x,y) (((x)+(y)-1)/(y))
#define all(v) (v).begin(), (v).end()
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
#define debug3(x,y,z) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<"\n"

typedef long long ll;
typedef pair<int, int> P;

int main(){
  int a;
  
  cin>>a;
  
  
  if(a>=30)cout<<"Yes";
  else cout<<"No";
  
  return 0;
}
