#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  string s;
  cin>>n>>s;
  bool r=false;
  rep(i,0,4){
    bool p[n];
    if(i%2==0) p[0]=false;
    else p[0]=true;
    if(i/2%2==0) p[1]=false;
    else p[1]=true;
    rep(j,2,n){
      if(s[j-1]=='o'){
        if(p[j-1]) p[j]=p[j-2];
        else p[j]=!p[j-2];
      }
      else{
        if(p[j-1]) p[j]=!p[j-2];
        else p[j]=p[j-2];
      }
    }
    bool q=true;
    if(s[n-1]=='o'){
      if(p[n-1]){
        if(p[n-2]!=p[0]) q=false;
      }
      else{
        if(p[n-2]==p[0]) q=false;
      }
    }
    else{
      if(p[n-1]){
        if(p[n-2]==p[0]) q=false;
      }
      else{
        if(p[n-2]!=p[0]) q=false;
      }
    }
    if(s[0]=='o'){
      if(p[0]){
        if(p[n-1]!=p[1]) q=false;
      }
      else{
        if(p[n-1]==p[1]) q=false;
      }
    }
    else{
      if(p[0]){
        if(p[n-1]==p[1]) q=false;
      }
      else{
        if(p[n-1]!=p[1]) q=false;
      }
    }
    if(q){
      rep(i,0,n){
        if(p[i]) cout<<'S';
        else cout<<'W';
      }
      r=true;
      break;
    }
  }
  if(!r) cout<<-1<<endl;
}