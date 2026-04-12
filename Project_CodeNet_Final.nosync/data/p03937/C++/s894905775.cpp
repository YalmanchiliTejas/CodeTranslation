#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const ll INF = (1LL << 31) - 1;
const double pi=acos(-1);


int main(){
  int h,w;
  cin >> h >> w;
  vector<string>a(h);
  rep(i,h)cin>>a[i];
  vector<int>vec;
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#')vec.push_back(j);
    }
  }
  int sum=0;
  rep(i,vec.size()-1){
    if(vec[i]+1==vec[i+1]||vec[i]==vec[i+1]){
      sum++;
      continue;
    }
    cout << "Impossible" << endl;
    return 0;
  }
  
  if(w+h-2==sum)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
  
    
}
