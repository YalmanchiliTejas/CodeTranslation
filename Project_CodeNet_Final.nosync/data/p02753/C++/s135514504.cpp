#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
void chmin(T &a,T b){
  if(a>b)a=b;
}
const int INF=1e9;
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  string s;cin>>s;
  for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(s[i]!=s[j])fin("Yes");
  fin("No");
}
