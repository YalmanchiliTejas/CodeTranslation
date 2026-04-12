/*{{{*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define FOR(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define FORR(i,a,b) for(ll (i)=(b)-1;(i)>=(a);(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl
#define CHMAX(a,b) a=max((a),(b))
#define CHMIN(a,b) a=min((a),(b))
/*}}}*/
int main() {
  ll h,w;
  cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];
  vector<bool> count(h+w,false);
  bool judge = true;
  REP(i,h){
    REP(j,w){
      if(a[i][j]=='#'){
        if(count[i+j]){
          judge = false;
          break;
        }else{
          count[i+j] = true;
        }
      }
    }
    if(!judge) break;
  }
  if(judge) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
