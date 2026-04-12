#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<string,string> Pstring;
typedef pair<double,double> Pdouble;

#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define Precision(i) cout << fixed << setprecision(i)

const double PI=3.14159265358979323846;
const int MAX = 510000;
const int MOD = 1000000007;


int main() {

  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  ll answer;
  if(a+b<=2*c){
    answer = x*a+y*b;
  }else{
    if(x>=y){
      if(a>=2*c){
        answer = x*2*c;
      }else{
        answer = y*2*c+(x-y)*a;
      }
    }else{
      if(b>=2*c){
        answer = y*2*c;
      }else{
        answer = x*2*c+(y-x)*b;
      }
    }
  }
  
  cout << answer << endl;
}