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
 
const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  vector<map<char,int>> mp(n);
  rep(i,n){
    string s;
    cin>>s;
    int sz=s.size();
    rep(j,sz){mp[i][s[j]]++;}
  }

  for(char i='a'; i<='z'; i++){
    int cnt=inf;
    rep(j,n){cnt=min(cnt,mp[j][i]);}
    rep(j,cnt){cout<<i;}
  }
  cout<<endl;
  return 0;
}
