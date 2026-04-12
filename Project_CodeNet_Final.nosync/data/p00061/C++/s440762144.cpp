#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
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

bool era[252525];

int main(){
  set<int> S;
  map<int,int> X;
  while(true){
    int a,b;
    scanf("%d,%d",&a,&b);
    if(a==0 && b==0)break;
    S.insert(b);
    X[a] = b;
  }
  map<int,int> rank;
  set<int>::iterator iter;
  iter = S.end();
  int k=1;
  do{
    --iter;
    rank[*iter] = k++;
  }while(iter!=S.begin());
  int n;
  while(~scanf("%d",&n))cout<<rank[X[n]]<<endl;
  return 0;
}