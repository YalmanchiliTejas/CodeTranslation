#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59

ll gcd(ll a,ll b){
  if(a<b) swap(a,b);
  if(a%b==0) return b;
  else return gcd(b,a%b);
}

ll m[52],p[52];

ll solve(ll n,ll k){
  if(k<=0) return 0;

  if(n==0) return 1;

  if(k==1) return 0;
  if(k==1+m[n-1]) return p[n-1];
  if(k==2+m[n-1]) return p[n-1]+1;
  if(k==m[n]) return p[n];
  if(k<=m[n-1]) return solve(n-1,k-1);
  if(k>2+m[n-1]) return p[n-1]+1+solve(n-1,k-2-m[n-1]);
  return 0;
}

int main(){
  ll i,j;
  ll n,x;
  cin>>n>>x;
  
  m[0]=1;
  p[0]=1;
  for(i=1;i<51;i++) {
    m[i]=3+2*m[i-1];
    p[i]=1+2*p[i-1];
  }
  
  cout<<solve(n,x)<<endl;


  return 0;
}
