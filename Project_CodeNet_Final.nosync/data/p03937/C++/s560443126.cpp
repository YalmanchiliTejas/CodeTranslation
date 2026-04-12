#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int h,w;cin>>h>>w;
  set<pair<int, int>> moved;
  rep(y, h){
    string s;cin>>s;
    rep(x,w){
      if(s[x]=='#')moved.insert(make_pair(y,x));
    }
  }

  bool f=true;
  rep(y, h){
    rep(x,w){
      bool d_r = !(moved.count(make_pair(y+1, x)) ^ moved.count(make_pair(y, x+1)));
      bool u_l = !(moved.count(make_pair(y-1, x)) ^ moved.count(make_pair(y, x-1)));

      if( (y==0 && x==0 && d_r) || (y==h-1 && x==w-1 && u_l) || !(y==0 && x==0)&&!(y==h-1 && x==w-1)&& 
 moved.count(make_pair(y,x)) && (u_l || d_r) ){
//cout<<y<<' '<<x<<'|'<<u_l<<' '<<d_r<<endl;
        f=false;break;
      }
    }
  }

  if(f) cout<<"Possible";
  else cout<<"Impossible";

  return 0;
}