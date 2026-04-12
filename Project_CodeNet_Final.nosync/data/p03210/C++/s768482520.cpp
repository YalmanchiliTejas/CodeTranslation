#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define INIT(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define INIT2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define LINY "YES\n"
#define Liny "Yes\n"
#define LINN "NO\n"
#define Linn "No\n"
#define umap unordered_map
//std::cout << std::setfill('0') << std::right << std::setw(4) << 12; // "0012"

ll min(ll x,ll y){return (x<y ? x:y);}
ll max(ll x,ll y){return (x>y ? x:y);}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a*b /gcd(a,b);}

int main(){
  int x; cin>>x;
  if(x==7 || x==5 || x==3){cout<<LINY;}
  else{cout<<LINN;}
}
