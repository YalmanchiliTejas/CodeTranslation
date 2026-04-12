#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  cin>>n;
  vector<int> a(n),b;
  rep(i,n) cin>>a[i];
  b=a;

  sort(a.begin(),a.end(),greater<int>());
  deque<int> d;
  d.push_back(a[a.size()-1]);
  a.pop_back();
  bool s=1;
  while(!a.empty()){
    if(s){
      d.push_back(a[0]); a.erase(a.begin());
      if(a.empty()) break;
      d.push_front(a[0]); a.erase(a.begin());
      s=0;
    }else{
      d.push_back(a[a.size()-1]); a.pop_back();
      if(a.empty()) break;
      d.push_front(a[a.size()-1]); a.pop_back();
      s=1;
    }
  }
  ll ans=0;
  for(int i=0; i<n-1; i++){
    ans+=abs(d[i+1]-d[i]);
  }

  sort(b.begin(),b.end());
  deque<int> p;
  p.push_back(b[b.size()-1]);
  b.pop_back();
  bool t=1;
  while(!b.empty()){
    if(t){
      p.push_back(b[0]); b.erase(b.begin());
      if(b.empty()) break;
      p.push_front(b[0]); b.erase(b.begin());
      t=0;
    }else{
      p.push_back(b[b.size()-1]); b.pop_back();
      if(b.empty()) break;
      p.push_front(b[b.size()-1]); b.pop_back();
      t=1;
    }
  }
  ll ans1=0;
  for(int i=0; i<n-1; i++){
    ans1+=abs(p[i+1]-p[i]);
  }
  cout<<max(ans,ans1)<<endl;
}

