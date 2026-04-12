#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,s,t;
  cin>>n>>s>>t;

  auto ask=
    [&](Int a,Int b){
      cout<<"? "<<a<<" "<<b<<endl;
      Int x;
      cin>>x;
      return x;
    };

  vector<Int> ds(n+1,0);
  vector<Int> dt(n+1,0);

  for(Int i=1;i<=n;i++){
    if(i==s||i==t) continue;
    ds[i]=ask(s,i);
    dt[i]=ask(t,i);
  }

  Int dist=ask(s,t);
  ds[t]=dt[s]=dist;

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int i=1;i<=n;i++){
    if(i==s||i==t) continue;
    if(ds[i]+dt[i]>dist) continue;
    vp.emplace_back(ds[i],i);
  }

  if(vp.empty()){
    cout<<"! "<<s<<" "<<t<<endl;
    return 0;
  }

  vp.emplace_back(ds[t],t);
  sort(vp.begin(),vp.end());

  Int pos=s;
  vector<Int> ans;
  ans.emplace_back(pos);

  Int i=0;
  while(pos!=t){
    while(1){
      //cerr<<":::"<<i<<" "<<vp.size()<<endl;
      Int k=vp[i].second;
      i++;
      if(ask(pos,k)+dt[k]==dt[pos]){
        pos=k;
        break;
      }
    }
    ans.emplace_back(pos);
  }

  cout<<"!";
  for(Int x:ans) cout<<" "<<x;
  cout<<endl;
  return 0;
}

