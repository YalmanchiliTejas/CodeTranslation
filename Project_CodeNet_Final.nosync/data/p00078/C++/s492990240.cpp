#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)
  
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()
  
#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

#define INF 1000000000

typedef long double Real;
#define EPS 1e-11
#define EQ(x) (-EPS<x && x<EPS)
typedef complex<Real> P;
Real dot(P a,P b){return real(conj(a)*b);}
Real cross(P a,P b){return imag(conj(a)*b);}

int mp[16][16];

int main(){
  while(true){
    int n;
    cin>>n;
    if(!n)break;
    REP(i,n)REP(j,n)mp[i][j]=0;
    int iter = 1;
    int y=n/2+1;
    int x=n/2;
    while(true){
      mp[y][x] = iter++;
      if(iter==n*n+1)break;
      ++y; ++x;
      while(x<0 || x>=n || y>=n || mp[y][x]!=0){
        if(x<0)x=n-1;
        else if(x>=n)x=0;
        else if(y>=n)y=0;
        else{
          --x;
          ++y;
        }
      }
    }
    REP(j,n){
      REP(i,n){
        printf("%4d",mp[j][i]);
      }
      printf("\n");
    }
  }
  return 0;
}