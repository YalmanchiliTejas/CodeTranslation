#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  ll n;cin>>n;
  string s;
  vector<int>a(26,0);
  
  rep(i,n){
    cin>>s;
    rep(j,26){
      char x='a'+j;
      if(i==0)a[j]+=count(all(s),x);
      else a[j]=min(a[j],(int)count(all(s),x));
    }
  }
  rep(i,26){
    rep(j,a[i])cout<<(char)('a'+i);
  }
}