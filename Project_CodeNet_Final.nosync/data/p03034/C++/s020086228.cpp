#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(),(x).end())
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(ll i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define db(x) cout<<#x<<"="<<x<<endl
#define deb(x) each(x.begin(),x.end(),(int& y){cout << y <<" ";})
template<class T>bool maxi(T &a,const T &b){if(a<b){ a=b; return 1;} return 0;}
template<class T>bool mini(T &a,const T &b){if(b<a){ a=b; return 1;} return 0;}
#define y0 y3487465 //j0
#define j1 j1347829 //j1
#define INF2 4000000000000000037
#define INF 1000000007
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;

//const int MAXN=100010;
//ll dp[MAXN][MAXN];

void Main(){

  ll N;cin>>N;

  vector<ll> dp[100010];

  ll s[N];
  rep(i,N){
    cin>>s[i];
  }

  rep(c,N){ // c, k
    dp[c].emplace_back(0);
  }

  ll ans=0;

  ll nidome[N]={};

  reps(c,1,N){
    for(ll k=1;(k+1)*c<N-1;k++){
      dp[c].emplace_back(dp[c][k-1]+s[N-1-k*c]+s[k*c]);
      if(maxi(nidome[N-1-k*c],c)==0 or maxi(nidome[k*c],c)==0){
        continue;
      }
      maxi(ans,dp[c][k]);
    }
  }

  cout<< ans<<"\n";
}

//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------
