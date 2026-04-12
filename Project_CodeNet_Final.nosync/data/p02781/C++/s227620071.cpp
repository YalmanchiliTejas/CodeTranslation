#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<string> vs;
typedef vector<bool> vb;

const ll mod=1e9+7;
const ll inf=1e16;

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m-1;i>=n;i--)
#define fi first
#define se second
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define eb(x) emplace_back(x)
#define all(x) x.begin(),x.end()
#define gll greater<ll>()

string n;
ll k;

ll dp[105][4][2];

void solve(){
 cin >> n >> k;
 ll l=n.size();

  
  dp[0][0][0]=1;
  
  rep(i,0,l){
   rep(j,0,4){
    rep(m,0,2){
      ll nd=n[i]-'0';
      rep(d,0,10){
       ll nj=j,nm=m;
       if(d!=0) nj++;
       if(nj>k) continue; 
       if(m==0){ 
        if(d>nd) continue;
        if(d<nd) nm=1; 
       }
       dp[i+1][nj][nm]+=dp[i][j][m]; 
      }
    }
   }
  }
 cout << dp[l][k][0]+dp[l][k][1] << endl;
}

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}  