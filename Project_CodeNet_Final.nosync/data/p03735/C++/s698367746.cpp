#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T, typename ...Ts>
vector<T> fusion(vector<T> bs,Ts... ts){
  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};
  initializer_list<Int>{(void(append(ts)),0)...};
  return bs;
}


template<typename V>
V compress(V v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
template<typename T>
map<T, Int> dict(const vector<T> &v){
  map<T, Int> res;
  for(Int i=0;i<(Int)v.size();i++)
    res[v[i]]=i;
  return res;
}
map<char, Int> dict(const string &v){
  return dict(vector<char>(v.begin(),v.end()));
}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> xs(n),ys(n);
  for(Int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  auto as=compress(fusion(xs,ys));
  auto dc=dict(as);
  if(as.size()==1) drop(0);

  Int ans=(as.back()-as.front())*(as.back()-as.front());

  // togathered
  {
    Int m=dc.size();
    vector< vector<Int> > G(m);
    for(Int i=0;i<n;i++){
      G[dc[xs[i]]].emplace_back(i);
      G[dc[ys[i]]].emplace_back(i);
    }

    Int cnt=0;
    vector<Int> app(n,0);
    for(Int l=0,r=0;l<m;l++){
      while(cnt<n&&r<m){
        for(Int i:G[r]){
          if(app[i]==0) cnt++;
          app[i]++;
        }
        r++;
      }
      if(cnt<n) break;

      chmin(ans,(as.back()-as.front())*(as[r-1]-as[l]));

      for(Int i:G[l]){
        app[i]--;
        if(app[i]==0) cnt--;
      }
    }
  }

  // separated
  {
    Int p=as.back(),q=as.front();
    for(Int i=0;i<n;i++){
      chmin(p,max(xs[i],ys[i]));
      chmax(q,min(xs[i],ys[i]));
    }
    chmin(ans,(as.back()-p)*(q-as.front()));
  }

  cout<<ans<<endl;
  return 0;
}
