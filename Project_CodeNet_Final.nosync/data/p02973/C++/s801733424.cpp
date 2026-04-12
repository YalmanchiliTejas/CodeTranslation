#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
const int mod=1e9+7;

int main(){
  int n;cin>>n;
  int a[n];rep(i,n)cin>>a[i];
  int m=1e9+7;
  int ctr=0;
  vector<int> p(2*n+5);
  rep(i,n)p[i]=-1;
  rep(i,n,2*n+5)p[i]=mod;
  rep(i,n){
    auto it=lower_bound(all(p),a[i]);
    --it;
    *it=a[i];
  }
  rep(i,2*n+5){
    if(p[i]!=-1&&p[i]!=mod)ctr++;
  }
  cout<<ctr<<endl;
}
