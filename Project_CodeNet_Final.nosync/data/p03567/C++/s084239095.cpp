#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin>>s;
  bool ans=false;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='A'&&s[i+1]=='C')ans=true;
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
