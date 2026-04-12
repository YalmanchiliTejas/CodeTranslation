#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(signed i=0;i<n;++i)
#define repi(n) rep(i,n)
#define int long long
#define str string
#define vint vector<int>
#define pint pair<int,int>
#define pb(a) push_back(a)
#define all(v) v.begin(),v.end()
#define yn(b) cout<<((b)?"Yes":"No")<<endl
#define YN(b) cout<<((b)?"YES":"NO")<<endl
#define call(a) for(auto t:a)cout<<t<<" ";cout<<endl
#define ENDL printf("\n");
#define debg(a) cout<<#a<<":"<<a<<endl;
#define SORT(a) sort(all(a));
#define INF 1LL<<60
#define inf INF
#define out(i) cout<<i<<endl;
int alp[300][300];
int min(int a,int b){if(a>b)return b;return a;}
signed main(){
  int n;
  cin>>n;
  vector<str> s(n);
  repi(n) cin>>s[i];
  str ans="";
  rep(i,n){
    rep(j,s[i].length()){
      alp[i][s[i][j]+0]++;
    }
  }
  for(int i='a';i<='z';++i){
    int chk=inf;
    rep(j,n){
      chk=min(chk,alp[j][i]);
    }
    rep(k,chk)ans+=('0'+(i-48));
  }
  SORT(ans);
  cout<<ans<<endl;

  return 0;
}

