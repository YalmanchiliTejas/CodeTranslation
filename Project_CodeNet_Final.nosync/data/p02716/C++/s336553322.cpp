#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
typedef long long int ll;
using namespace std;


ll N;
static ll a[200000];
static ll maxi[200000];
static ll cumsum[200002];
static ll diff[200001];
static ll maxi0[200001], maxi1[200001];

int main(){
  cin >> N;
  for(ll i=0;i<N;i++) cin >> a[i];

  for(ll i=2;i<=N+1;i++){
    cumsum[i] = cumsum[i-2] + a[i-2];
  }
  for(ll i=0;i<=N;i++){
    diff[i] = cumsum[i] - cumsum[i+1];
    // cerr << diff[i] << endl;
  }
  // cerr << endl;
  maxi0[0] = diff[0];
  for(ll i=2;i<=N;i+=2){
    maxi0[i] = max(maxi0[i-2], diff[i]);
    // cerr << maxi0[i] << endl;
  }
  // cerr << endl;
  maxi1[N] = diff[N];
  for(ll i=N-2;i>=1;i-=2){
    maxi1[i] = max(maxi1[i+2], diff[i]);
    // cerr << maxi1[i] << endl;
  }

  ll ans;
  if (N%2){
    ans = LLONG_MIN;
    for(ll i=0;i<N;i+=2){
      ll cand = cumsum[N+1] + maxi0[i] + maxi1[i+1];
      ans = max(ans, cand);
    }
  }else{
    ans = cumsum[N+1] + maxi0[N];
  }

  cout << ans << endl;

  return 0;
}