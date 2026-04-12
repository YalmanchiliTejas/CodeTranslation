#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
 //pair<pair<int,int>,int> p[100001];
 vector<int> hen[10];
 bool used[10]={};
 int bfs(int a,int t){
   if(t==1){
     return 1;
   }
   int ans=0;
   for(int i=0;i<hen[a].size();i++){
     if(!used[hen[a][i]]){
       used[hen[a][i]]=true;
       ans+=bfs(hen[a][i],t-1);
       used[hen[a][i]]=false;
     }
   }
   return ans;
 }
signed main() {
int n,m;
cin>>n>>m;

int a,b;
for(int i=0;i<m;i++){
  cin>>a>>b;a--;b--;
  hen[a].push_back(b);
  hen[b].push_back(a);
}
used[0]=true;
cout<<bfs(0,n);


return 0;
}
