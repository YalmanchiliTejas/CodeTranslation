#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)  
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RVSORT(v) sort(v.rbegin(), v.rend());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int gcd(int a,int b){return b?gcd(b,a%b):a;}

ll modpow(ll n,ll k){
  if(k == 1){
    return n;
  }else if(k == 0){
    return 1;
  }else if(k%2==0){
    ll memo = modpow(n,k/2)%MOD;
    return memo*memo%MOD;
  }else{
    return n * modpow(n,k-1)%MOD;
  }
}

int main(){

  int n;
  cin>>n;
  int a[n];
  REP(i,n){
    cin>>a[i];
  }

  vector<int> v;
  v.pb(a[0]);

  for(int i=1;i<n;i++){
    auto Iter = lower_bound(v.begin(),v.end(),a[i]);
    if(Iter==v.begin()){
      v.insert(v.begin(),a[i]);
    }else{
      Iter--;
      *Iter = a[i];
    }
  }
  cout<<v.size()<<endl;

 

  return 0;
}