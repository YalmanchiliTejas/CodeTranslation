#include <bits/stdc++.h>
 
using namespace std;
#define int long long


 const int MAX = 1001;
const int MOD = 1000000007;



signed main(){
 
   int n,m;
   cin>>n>>m;
   int s,t;
   cin>>s>>t;
   s--;t--;
   int ds[n],cs[n]={},dt[n],ct[n]={};
   vector<pair<int,int>> hen[n];
   int u,v,d;
   for(int i=0;i<m;i++){
       cin>>u>>v>>d;
       hen[u-1].push_back(make_pair(v-1,d));
       hen[v-1].push_back(make_pair(u-1,d));

   }
   for(int i=0;i<n;i++){
       ds[i]=LLONG_MAX;
       dt[i]=LLONG_MAX;
   }

    ds[s]=0;cs[s]=1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
    que.push(make_pair(0,s));
    
    int p,q;
    while(!que.empty()){
        p=que.top().second;q=que.top().first;
        que.pop();
        if(ds[p]<q)continue;
        for(int i=0;i<hen[p].size();i++){
            if(ds[hen[p][i].first]==ds[p]+hen[p][i].second){
            //   cerr<<p<<' '<<hen[p][i].first<<endl;
                cs[hen[p][i].first]=(cs[hen[p][i].first]+cs[p])%MOD;
            }
            if(ds[hen[p][i].first]>ds[p]+hen[p][i].second){
                ds[hen[p][i].first]=ds[p]+hen[p][i].second;
                cs[hen[p][i].first]=cs[p];
                que.push(make_pair(ds[hen[p][i].first],hen[p][i].first));
            }
            
        }
    }
  
    dt[t]=0;que.push(make_pair(0,t));ct[t]=1;
    while(!que.empty()){
        p=que.top().second;q=que.top().first;
        que.pop();
        if(dt[p]<q)continue;
        for(int i=0;i<hen[p].size();i++){
            if(dt[hen[p][i].first]==dt[p]+hen[p][i].second){
               
                ct[hen[p][i].first]=(ct[hen[p][i].first]+ct[p])%MOD;
            }
            if(dt[hen[p][i].first]>dt[p]+hen[p][i].second){
                dt[hen[p][i].first]=dt[p]+hen[p][i].second;
                ct[hen[p][i].first]=ct[p];
                que.push(make_pair(dt[hen[p][i].first],hen[p][i].first));
            }
            
        }
    }
    
    int mind=ds[t],ans=0,w;
    for(int i=0;i<n;i++){
       if(ds[i]+dt[i]!=mind)continue;
       if(2*ds[i]==mind){
         //  cerr<<cs[i]<<' '<<ct[i]<<endl;
         w=(cs[i]*cs[i])%MOD;w=(w*ct[i])%MOD;w=(w*ct[i])%MOD;
           ans=(ans+w)%MOD;
       }
       if(2*ds[i]<mind){
           for(int j=0;j<hen[i].size();j++){
               if(ds[i]+hen[i][j].second==ds[hen[i][j].first]&&ds[hen[i][j].first]+dt[hen[i][j].first]==mind&&2*ds[hen[i][j].first]>mind){
                   w=(cs[i]*cs[i])%MOD;w=(w*ct[hen[i][j].first])%MOD;w=(w*ct[hen[i][j].first])%MOD;
                   ans=(ans+w)%MOD;
               }
           }
       }
    }
   // for(int i=0;i<n;i++)cerr<<ds[i]<<' ';
  //  cerr<<ans<<' '<<mind<<endl;
    cout<<(MOD+cs[t]*cs[t]-ans)%MOD;



   return 0;
}