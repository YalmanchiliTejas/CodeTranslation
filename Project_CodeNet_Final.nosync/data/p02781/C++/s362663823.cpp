#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int ctoi(char c){
  if(c=='1') return 1;
  if(c=='2') return 2;
  if(c=='3') return 3;
  if(c=='4') return 4;
  if(c=='5') return 5;
  if(c=='6') return 6;
  if(c=='7') return 7;
  if(c=='8') return 8;
  if(c=='9') return 9;
  if(c=='0') return 0;
}

int main(){
  string s;
  cin>>s;
  int k;
  cin>>k;
  int n=s.size();
  int ans=0;
  if(k==1){
    ans=(n-1)*9+ctoi(s.at(0));
  }
  
  if(k==2){
    rep(i,2,n){
      ans+=81*(i-1);
    }
    ans+=(ctoi(s.at(0))-1)*9*(n-1);
    bool cur=false;
    rep(i,1,n){
      if(!cur) ans+=ctoi(s.at(i));
      else ans+=9;
      if(ctoi(s.at(i))!=0) cur=true;
    }
  }
  
  if(k==3){
    rep(i,3,n){
      ans+=729*(i-1)*(i-2)/2;
    }
    ans+=(ctoi(s.at(0))-1)*81*(n-1)*(n-2)/2;
    int now=0;
    rep(i,1,n){
      if(s.at(i)!='0'){
        now=i;
        break;
      }
    }
    if(now!=0){
      rep(i,2,n-now){
        ans+=81*(i-1);
      }
      ans+=(ctoi(s.at(now))-1)*9*(n-now-1);
      bool cur=false;
      rep(i,1,n-now){
        if(!cur) ans+=ctoi(s.at(i+now));
        else ans+=9;
        if(ctoi(s.at(i+now))!=0) cur=true;
      }
    }
  }
  
  cout<<ans<<endl;
}