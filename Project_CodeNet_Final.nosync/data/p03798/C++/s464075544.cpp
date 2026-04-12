#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll n;cin>>n;
  string s;cin>>s;
  vb zoo(n);
  bool ok=false;
  rep(k,0,2){
    zoo[0]=k;
    rep(j,0,2){
      zoo[1]=j;
      rep(i,2,n){
        if((zoo[i-1]&&s[i-1]=='o')||(!zoo[i-1]&&s[i-1]=='x')){
          zoo[i]=zoo[i-2];
        }
        else{
          zoo[i]=!zoo[i-2];
        }
      }
      if((zoo[0]&&s[0]=='o')||(!zoo[0]&&s[0]=='x')){
          if(zoo[1]==zoo[n-1]){
            if((zoo[n-1]&&s[n-1]=='o')||(!zoo[n-1]&&s[n-1]=='x')){
              if(zoo[n-2]==zoo[0])ok=true;
            }
            else{
              if(zoo[n-2]!=zoo[0])ok=true;
            }
          }
    
        }
      else{
        if(zoo[1]!=zoo[n-1]){
          if((zoo[n-1]&&s[n-1]=='o')||(!zoo[n-1]&&s[n-1]=='x')){
              if(zoo[n-2]==zoo[0])ok=true;
            }
            else{
              if(zoo[n-2]!=zoo[0])ok=true;
            }
        }
      }
      if(ok){
        rep(i,0,n){
          if(zoo[i])cout<<"S";
          else cout<<"W";
        }
        cout<<endl;
        break;
      }
    }
    if(ok)break;
  }
  if(!ok)cout<<-1<<endl;
}
