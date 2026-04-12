#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

// g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -o 

int main(){
 ll n,m,x;
 cin>>n>>x>>m;
 ll a=x,sum=x,br;
 map<ll,ll>vis;
 map<ll,ll>stime;
 vis[x]=1;
 ll time=1;
 ll f=0;
 stime[1]=x;
 for(int i=1;i<min(n,m);i++){
  a=((a*a)%m);
  sum+=a;
  if(vis[a]>0){
   br=i+1;
//    cout<<a<<" : "<<vis[a]<<"\n";
   f=vis[a];
   break;
  }
  vis[a]=++time;
  stime[vis[a]]=sum;
 }
//  for(auto x:vis)cout<<x.first<<" "<<x.second<<"\n";
//  cout<<"\n";
//  for(auto x:stime)cout<<x.first<<" "<<x.second<<"\n";
//  cout<<"\n";
//  cout<<br<<" "<<f<<" "<<a<<"\n";
 if(f){
  sum+=(((n-br)/(br-f))*(sum-stime[f]));
  n-=br;
  n%=(br-f);
  for(int i=1;i<=n;i++){
   a=((a*a)%m);
   sum+=a;
  }
 }
 cout<<sum<<"\n";
 return 0;
}
