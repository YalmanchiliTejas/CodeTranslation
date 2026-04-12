#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> data;
  vector<bool> t(w,false);
  rep(i,h){
    string s; cin >> s;
    bool flag=false;
    rep(j,w){
      if(s[j]=='.'){
      } else {
        flag = true;
        t[j] = true;
      }      
    }
    if(flag){data.emplace_back(s);}
  }
  
  rep(i,data.size()){
    rep(j,w)if(t[j]){cout<<data[i][j];}
    cout<<endl;
  }
  return 0;
}