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

int n;
string s;
 
vector<bool> dfs(vector<bool> &tmp, int cnt){
  if(cnt==n){
    if(tmp[n]==tmp[0]){
      if((tmp[0]  && s[0]=='o' && tmp[1]==tmp[n-1])||
         (tmp[0]  && s[0]=='x' && tmp[1]!=tmp[n-1])||
         (!tmp[0] && s[0]=='x' && tmp[1]==tmp[n-1])||
         (!tmp[0] && s[0]=='o' && tmp[1]!=tmp[n-1])){
        tmp.pop_back();
        return tmp;
      }
    }
    return tmp;
  }
  
  if((tmp[cnt] == true && s[cnt] == 'o')||(tmp[cnt] == false && s[cnt] == 'x')){
    if(cnt!=0){ 
      tmp.emplace_back(tmp[cnt-1]);
      vector<bool> cur = dfs(tmp, cnt+1); 
      if(cur.size()==s.size()){ return cur;}
    } else {
      vector<bool> tmps = tmp; tmps.emplace_back(true);
      vector<bool> cur = dfs(tmps, cnt+1); 
      if(cur.size()==s.size()){ return cur;}
      
      vector<bool> tmpw = tmp; tmpw.emplace_back(false);
      cur = dfs(tmpw, cnt+1); 
      if(cur.size()==s.size()){ return cur;}
    }
  }

  if((tmp[cnt] == true && s[cnt] == 'x')||(tmp[cnt] == false && s[cnt] == 'o')){
    if(cnt!=0){ 
      tmp.emplace_back(!tmp[cnt-1]);
      vector<bool> cur = dfs(tmp, cnt+1); 
      if(cur.size()==s.size()){ return cur;}
    } else {
      vector<bool> tmps = tmp; tmps.emplace_back(true);
      vector<bool> cur = dfs(tmps, cnt+1); 
      if(cur.size()==s.size()){ return cur;}
      
      vector<bool> tmpw = tmp; tmpw.emplace_back(false);
      cur = dfs(tmpw, cnt+1); 
      if(cur.size()==s.size()){ return cur;}
    }
  }
  vector<bool> dame(1,false);
  return dame;
}

int main() {
  cin >> n >> s;
  vector<bool> a;
  a.emplace_back(true);
  a = dfs(a,0);
  if(a.size()==s.size()){
    rep(i,n){
      if(a[i]){cout<<"S";}else{cout<<"W";}
    }
    cout<<endl; return 0;
  }

  vector<bool> b;
  b.emplace_back(false);
  b = dfs(b,0);
  if(b.size()==s.size()){
    rep(i,n){
      if(b[i]){cout<<"S";}else{cout<<"W";}
    }
    cout<<endl; return 0;
  }
  
  cout << -1 << endl;
  return 0;
}  
