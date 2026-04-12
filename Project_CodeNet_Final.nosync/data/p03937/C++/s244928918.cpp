#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);


int main(){
  int h,w;
  cin >> h >> w;
  int sum=0;
  rep(i,h){
    rep(j,w){
      char c;
      cin >> c;
      if(c=='#')sum++;
    }
  }
  if(sum==h+w-1)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
      
}
