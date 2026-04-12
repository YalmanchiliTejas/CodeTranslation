#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define mod 998244353
#define int long long int
using namespace std;
vector<int>seg;
vector<int>lazy;
int S;
void build(){
      S=(1<<(int)ceil(log2(seg.size())));
      int l=S-seg.size();
      for(int i=0;i<l;i++)seg.pb(0);
      reverse(all(seg));
      for(int i=1;i<seg.size();i+=2)seg.pb(max(seg[i],seg[i-1]));
      seg.pb(0);
      reverse(all(seg));
      lazy=vector<int>(seg.size()*4,0);
}
void push(int j){
      if(j>=seg.size())return;
      seg[j]+=lazy[j];
      lazy[j*2]+=lazy[j];
      lazy[j*2+1]+=lazy[j];
      lazy[j]=0;
}
void update(int j){
      while(j>0){
            push(j);
            push(j*2);
            push(j*2+1);
            if(j*2+1<seg.size())
            seg[j]=max(seg[j*2],seg[j*2+1]);
            j/=2;
      }
}
void rangeupdate(int j,int a,int b,int x,int y,int key){
      push(j);
      if(y<a||b<x)return;
      if(a<=x&&y<=b){
            lazy[j]+=key;
            push(j);
            update(j);
      }
      else{
            rangeupdate(j*2,a,b,x,(x+y)/2,key);
            rangeupdate(j*2+1,a,b,(x+y)/2+1,y,key);
      }
}
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
   //   freopen("q.gir","r",stdin);
   //   freopen("q.cik","w",stdout);
      int n,m;
      cin>>n>>m;
      seg.resize(n+1,0);
      build();
      map<int,vector<int> > X;
      vector<pair<ii,int> >arr(m+1);
      for(int i=1;i<=m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            arr[i]={{x,y},z};
            X[x].pb(i);
            X[y].pb(-i);
      }
      int sum=0,ans=0;
      for(int x=1;x<=n;x++){
            if(X.count(x)){
                  vector<int>&Q=X[x];
                  for(int i=0;i<Q.size();i++){
                        if(Q[i]>0){
                              sum+=arr[Q[i]].second;
                        }
                  }
            }
            ans=max(ans,sum+seg[1]);
            rangeupdate(1,x,x,0,S-1,seg[1]);
            if(X.count(x)){
                  vector<int>&Q=X[x];
                  for(int i=0;i<Q.size();i++){
                        if(Q[i]<0){
                              pair<ii,int>& p=arr[-Q[i]];
                              rangeupdate(1,p.first.first,x,0,S-1,p.second);
                              sum-=p.second;
                        }
                  }
            }
      }
      cout<<ans;
}
