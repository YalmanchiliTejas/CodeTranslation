#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;

vector<ll> a;

ll dp(vector<vector<ll>> &memo,int l,int r){
  if(memo.at(l).at(r)!=-1e18) return memo.at(l).at(r);
  if(l==r)  return memo.at(l).at(r)=0;
  if(l>r) return -1e18;

  memo.at(l).at(r)=max(-dp(memo,l,r-1)+a.at(r-1),-dp(memo,l+1,r)+a.at(l));
  //cout << l << "," << r << "," << memo.at(l).at(r) << endl;
  return memo.at(l).at(r);
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin >> N;
  a.resize(N);
  for(int i=0;i<N;i++)  cin >> a.at(i);

  vector<vector<ll>> memo(N+1,vector<ll>(N+1,-1e18));
  cout << dp(memo,0,N) << endl;

  return 0;
}