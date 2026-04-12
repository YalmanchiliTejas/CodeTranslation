#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
int main() {
  int n;
  cin>>n;
  vector<string>s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  map<char,int>ans;
  for(int j=0;j<s[0].size();j++){
    ans[s[0][j]]++;
  }

  for(int i=0;i<n;i++){
    map<char,int>k;
    for(int j=0;j<s[i].size();j++){
      k[s[i][j]]++;
    }
    for(auto j='a';j<='z';j++){
      ans[j]=min(ans[j],k[j]);
    }
  }
  string p;
  for(auto c:ans){
    int v=c.second;
    for(int i=0;i<v;i++){
      p.push_back(c.first);
    }
  }
  sort(p.begin(),p.end());
  cout<<p<<endl;
  return 0;
}