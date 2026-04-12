#include <bits/stdc++.h>
using namespace std;
#define int lint
typedef long long lint;
typedef pair<int,int> P;
const int    INF=(int)1e9;
const int    MOD=(int)1e9+7;
const double EPS=(double)1e-10;
struct Accelerate_Cin{
    Accelerate_Cin(){
        cin.tie(0); ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);
    };
};

signed main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;

  map<char,int>mp;
  mp[X]=A;
  mp[Y]=B;

  int ans=0;
  if(C*2<A+B){
    ans+=C*2*min(X,Y);
  }else{
    ans+=A*X+B*Y;
    cout<<ans<<"\n";
    return 0;
  }

  int l=X+Y-min(X,Y)*2;

  if(2*C<mp[max(X,Y)]){
    ans+=2*C*l;
    cout<<ans<<"\n";
  }else{
    ans+=l*mp[max(X,Y)];
    cout<<ans<<"\n";
  }

  return 0;
}
