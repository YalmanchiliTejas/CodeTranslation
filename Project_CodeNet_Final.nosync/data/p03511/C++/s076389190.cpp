#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int l;
  string s,t;
  cin>>l>>s>>t;
  
  Int n=s.size(),m=t.size();
  auto calc=[&](Int a,Int f){
    Int b=(l-a*n)/m;
    assert(a*n+b*m==l);
    string res;
    if(f) for(Int i=0;i<a;i++) res+=s;
    for(Int i=0;i<b;i++) res+=t;    
    if(!f) for(Int i=0;i<a;i++) res+=s;
    return res;
  };
  
  Int x=l+1,y=-1;
  for(Int i=0;i*n<=l;i++){
    Int a=i,b=(l-a*n)/m;
    if(a*n+b*m==l){
      chmin(x,a);
      chmax(y,a);
    }
  }
  //cout<<x<<" "<<y<<endl;
  string ans=calc(x,0);
  chmin(ans,calc(x,0));
  chmin(ans,calc(x,1));
  chmin(ans,calc(y,0));
  chmin(ans,calc(y,1));
  
  cout<<ans<<endl;
  return 0;
}
