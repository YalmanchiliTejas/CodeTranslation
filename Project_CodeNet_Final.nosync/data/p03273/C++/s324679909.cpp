#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll H,W;
  cin>>H>>W;
  vector<string> graph(0);
  for(ll i=0;i<H;i++){
    string str;
    cin>>str;
    ll count=0;
    for(ll j=0;j<W;j++){
      if(str.at(j)=='#'){count++;}
    }
    if(count>0){graph.push_back(str);}
  }
  vector<ll> vec(0);
  for(ll i=0;i<W;i++){
    ll count=0;
    for(ll j=0;j<(ll)graph.size();j++){
      if(graph.at(j).at(i)=='#'){count++;}
    }
    if(count>0){vec.push_back(i);}
  }
  for(ll i=0;i<(ll)graph.size();i++){
    for(ll j=0;j<(ll)vec.size();j++){
      cout<<graph.at(i).at(vec.at(j));
    }
    cout<<endl;
  }
}