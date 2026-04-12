#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   map<int, int> ma;
   for(int i=n-1; i>=0; i--){
      auto it=ma.upper_bound(a[i]);
      if(it!=ma.end()){
         if(it->second==1) ma.erase(it);
         else it->second--;
      }
      ma[a[i]]++;
   }
   int ans=0;
   for(P p : ma){
      ans+=p.second;
   }

   cout<<ans<<endl;
   return 0;
}
