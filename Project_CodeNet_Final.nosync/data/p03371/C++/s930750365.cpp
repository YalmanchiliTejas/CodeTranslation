#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll res = 0;
  if(a+b <= 2*c){
    res += a*x+b*y;
  }else if(x < y){
    res += 2*c*x + (y-x)*(min(b,2*c));
  }else{
    res += 2*y*c + (x-y)*(min(a,2*c));
  }
  cout << res << endl;
  return 0;
}



