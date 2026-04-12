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
vl modinv;
void fillModInv(ll n, ll mod){
  modinv = vl(n+1);
  modinv[1] = 1;
  FOR(i,2,n+1){
    modinv[i] = modinv[mod%i] * (mod - mod/i) % mod;
  }
}
/*}}}*/
int main() {
  string s;
  cin >> s;

  string ans = "Yes";
  if(s[0]==s[1] && s[1]==s[2] && s[0]==s[2]) ans = "No";
  
  //cout << fixed << setprecision(10);
  cout << ans << endl;
  return 0;
}
