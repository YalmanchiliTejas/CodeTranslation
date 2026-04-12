#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  vector<ll> b(n),c;
  b=a;
  reverse(b.begin(),b.end());
  ll d=0;
  for(int i=n/2-1;i>=0;i--){
    if(i%2==0)
      c.push_back(a.at(i));
    else
      c.push_back(b.at(i));
  }
  for(int i=0;i<n/2;i++){
    if(i%2==0)
      c.push_back(b.at(i));
    else
      c.push_back(a.at(i));
  }
  if(n%2==1){
    if(abs(c.front()-a.at(n/2))>abs(c.back()-a.at(n/2)))
      c.insert(c.begin(),a.at(n/2));
    else
      c.push_back(a.at(n/2));
  }
  for(int i=1;i<n;i++){
    d+=abs(c.at(i)-c.at(i-1));
  }
  cout<<d;
}