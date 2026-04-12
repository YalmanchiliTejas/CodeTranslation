#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

//最後をとっている場合
// ll dptake[MAX][MAX];
//最後をとっていない場合
// ll dpnot[MAX][MAX];

int main(){
  ll N;cin>>N;
  vector<ll> a(N);
  rep(i,N) cin>>a[i];


  ll ans = 0;

  //最後をとっている場合
  ll dptake[MAX][3];

  //最後をとっていない場合
  ll dpnot[MAX][3];


  dptake[0][1] = a[0];

  for(ll i = 1; i < N; i++){
    if(i % 2 == 1){
      //notで遅れ
      dpnot[i][0] = max(dpnot[i-1][0], dptake[i-1][0]);
      //takeして進んでいる
      dptake[i][1] = dpnot[i-1][0] + a[i];
      //notして進んでいる
      dpnot[i][1] = dptake[i-1][1];
    }
    else{
      //takeで遅れている
      dptake[i][0] = dpnot[i-1][0] + a[i];
      //notで遅れ
      dpnot[i][0] = max(dptake[i-1][1] , dpnot[i-1][1]);
      //takeで進んでいる
      dptake[i][1] = dpnot[i-1][1] + a[i];
    }
  }

  // cout<<dptake[N-1][1]<<endl;
  if(N%2==0){
    cout<<max(dptake[N-1][1], dpnot[N-1][1])<<endl;
  }
  else cout<<max(dptake[N-1][0], dpnot[N-1][0])<<endl;

}
