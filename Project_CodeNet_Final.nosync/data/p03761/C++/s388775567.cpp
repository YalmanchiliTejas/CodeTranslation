#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define out(ans) cout << ans << endl;
const ll mod = 1e9 + 7;


int main(){

  int n;cin>>n;
  vector<string>s[55];
  vector<int>v(26,50),h(26,0);

  map<char,int>mp;
  string str;

  rep(i,0,n){

    cin>>str;

    rep(j,0,str.size()){
      mp[str[j]-'a']++;
    }

    for(map<char,int>::iterator itr=mp.begin();itr!=mp.end();itr++){
      h[(int)itr->first]=itr->second;
    }
    rep(i,0,26){
      v[i]=min(v[i],h[i]);
      h[i]=0;
    }
    mp.clear();
  }

  rep(i,0,26){
    rep(j,0,v[i]){
      cout<<(char)('a'+i);
    }
  }
  cout<<endl;

  return 0;
}
