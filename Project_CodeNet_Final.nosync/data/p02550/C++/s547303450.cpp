#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end



int main(){
   ll n; cin>>n;
   int x,m; cin>>x>>m;
   if(n<=10101010){
      ll res=0; int cur=x;
      while(n){
         res+=cur;
         cur=(1LL*cur*cur)%m; n--;
      }
      cout<<res<<endl; return 0;
   }
   map<int,int> rs; int idx=0,cur=x,eq=-1;
   while(1){
      if(rs.count(cur)){
         eq=cur; break;
      }
      rs[cur]=idx;
      cur=(1LL*cur*cur)%m; idx++;
   }
   ll res=0;
   if(cur==0){
      cur=x;
      goto fail;
   }
   if((int)rs.size()<=n){
      for(auto& add:rs)res+=add.first;
      n-=rs.size(); cur=eq; idx=0;
      rs.clear();
      while(1){
         if(rs.count(cur))break;
         rs[cur]=idx++; cur=(1LL*cur*cur)%m;
      }
      ll cir=0;
      for(auto& add:rs)cir+=add.first;
      res+=cir*(n/(int)rs.size()); n%=rs.size();
   }
   else cur=x;
   fail:;
   while(n){
      res+=cur;
      cur=(1LL*cur*cur)%m; n--;
      if(cur==0)break;
   }
   cout<<res<<endl;
   return 0;
}
