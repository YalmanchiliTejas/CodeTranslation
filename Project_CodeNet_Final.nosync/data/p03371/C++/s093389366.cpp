#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;
const ll INF = 1e12;






int main(){
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll sum  = INF;
  REP(i,x+1){
    ll res = i*a;
    if(x-i >= y){
      res += 2*c*(x-i);
    }
    else{
      res += 2*c*(x-i);
      int r = y;
      r -= (x-i);
      if(b <= 2*c){
	res += b*r;
      }
      else
	res += r*2*c;
      
    }
    sum = min(sum,res);
  }
  cout << sum << endl;
  return 0;
}
