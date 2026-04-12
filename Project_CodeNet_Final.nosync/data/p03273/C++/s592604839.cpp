#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
 
int main() {

  int h,w;
  int i=0;
  int k=0;
  int l=0;
  int j=0;
  cin>>h>>w;
  int count[h];
  int counter[w];
  rep(s,h){count[s]=0;}
  rep(t,w){counter[t]=0;}
  
vector<vector<char>>a(h,vector<char>(w));
  rep(i,h){
  rep(j,w){cin>>a.at(i).at(j);}}
  
  rep(i,h){
  rep(j,w){if(a.at(i).at(j)=='#'){count[i]++;counter[j]++;}}}
  
  rep(i,h){ if(count[i]!=0){
    rep(j,w){
      if(counter[j]!=0){
        cout<<a.at(i).at(j);}
    		}cout<<endl;}
  }

}

