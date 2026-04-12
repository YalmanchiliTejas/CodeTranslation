#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}


signed main(){
  string str;
  cin>>str;
  int ans = 0;
  for(int i=0;i<(int)str.size()-1;i++){
    if(str[i] == 'A' && str[i+1] == 'C') ans = 1;
  }

  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
