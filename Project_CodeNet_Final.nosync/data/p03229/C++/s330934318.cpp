#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  
  cin >> n;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  vector<int>b(n);
  rep(i,n){
    if(i%2==0){
      b.at(i)=a.at(i/2);
    }
    else{
      b.at(i)=a.at(n-(i+1)/2);
    }
  }
  long ans=0;
  rep(i,n-1){
    ans+=abs(b.at(i+1)-b.at(i));
  }
  if(n%2==0){
    ans+=abs(b.at(n-2)-b.at(0));
  }
  else{
    ans+=abs(b.at(n-3)-b.at(0));
  }
  
  reverse(a.begin(),a.end());
  vector<int>c(n);
  rep(i,n){
    if(i%2==0){
      c.at(i)=a.at(i/2);
    }
    else{
      c.at(i)=a.at(n-(i+1)/2);
    }
  }
  long ans2=0;
  rep(i,n-1){
    ans2+=abs(c.at(i+1)-c.at(i));
  }
  if(n%2==0){
    ans2+=abs(c.at(n-2)-c.at(0));
  }
  else{
    ans2+=abs(c.at(n-3)-c.at(0));
  }
  cout<<max(ans,ans2)<<endl; 
}