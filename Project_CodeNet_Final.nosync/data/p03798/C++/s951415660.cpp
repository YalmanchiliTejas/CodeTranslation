#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define lb(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define ub(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
using Pair = pair<ll,pair<int,int>>;
#define pq priority_queue<Pair, vector<Pair>, greater<Pair>> 
const ll mod=1000000007;
//const ll mod=998244353;
const ld pi=acos(-1.0);
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  string s;
  cin>>n>>s;

  vector<int> p(n,-1);
  auto q=p;
  q[0]=0,q[n-1]=0;
  if(q[0]==0 && s[0]=='o') q[1]=q[n-1];
  if(q[0]==0 && s[0]=='x') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='o') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='x') q[1]=q[n-1];

  for(int i=1;i<=n-3;i++){
    if(q[i]==0 && s[i]=='o') q[i+1]=q[i-1];
    if(q[i]==0 && s[i]=='x') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='o') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='x') q[i+1]=q[i-1];
  }
  bool ok=true;
  if(q[n-2]==0 && s[n-2]=='o' && q[n-1]!=q[n-3]) ok=false;
  if(q[n-2]==0 && s[n-2]=='x' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='o' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='x' && q[n-1]!=q[n-3]) ok=false;

  if(q[n-1]==0 && s[n-1]=='o' && q[0]!=q[n-2]) ok=false;
  if(q[n-1]==0 && s[n-1]=='x' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='o' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='x' && q[0]!=q[n-2]) ok=false;

  if(ok){
    rep(i,n){
      if(q[i]) cout << "W";
      else cout << "S";
    }
    cout << endl;
    return 0;
  }


  q=p;
  q[0]=0,q[n-1]=1;
  if(q[0]==0 && s[0]=='o') q[1]=q[n-1];
  if(q[0]==0 && s[0]=='x') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='o') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='x') q[1]=q[n-1];

  for(int i=1;i<=n-3;i++){
    if(q[i]==0 && s[i]=='o') q[i+1]=q[i-1];
    if(q[i]==0 && s[i]=='x') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='o') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='x') q[i+1]=q[i-1];
  }
  ok=true;
  if(q[n-2]==0 && s[n-2]=='o' && q[n-1]!=q[n-3]) ok=false;
  if(q[n-2]==0 && s[n-2]=='x' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='o' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='x' && q[n-1]!=q[n-3]) ok=false;

  if(q[n-1]==0 && s[n-1]=='o' && q[0]!=q[n-2]) ok=false;
  if(q[n-1]==0 && s[n-1]=='x' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='o' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='x' && q[0]!=q[n-2]) ok=false;

  if(ok){
    rep(i,n){
      if(q[i]) cout << "W";
      else cout << "S";
    }
    cout << endl;
    return 0;
  }

  q=p;
  q[0]=1,q[n-1]=0;
  if(q[0]==0 && s[0]=='o') q[1]=q[n-1];
  if(q[0]==0 && s[0]=='x') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='o') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='x') q[1]=q[n-1];
  
  for(int i=1;i<=n-3;i++){
    if(q[i]==0 && s[i]=='o') q[i+1]=q[i-1];
    if(q[i]==0 && s[i]=='x') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='o') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='x') q[i+1]=q[i-1];
  }
  ok=true;
  if(q[n-2]==0 && s[n-2]=='o' && q[n-1]!=q[n-3]) ok=false;
  if(q[n-2]==0 && s[n-2]=='x' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='o' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='x' && q[n-1]!=q[n-3]) ok=false;

  if(q[n-1]==0 && s[n-1]=='o' && q[0]!=q[n-2]) ok=false;
  if(q[n-1]==0 && s[n-1]=='x' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='o' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='x' && q[0]!=q[n-2]) ok=false;

  if(ok){
    rep(i,n){
      if(q[i]) cout << "W";
      else cout << "S";
    }
    cout << endl;
    return 0;
  }

  q=p;
  q[0]=1,q[n-1]=1;
  if(q[0]==0 && s[0]=='o') q[1]=q[n-1];
  if(q[0]==0 && s[0]=='x') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='o') q[1]=1-q[n-1];
  if(q[0]==1 && s[0]=='x') q[1]=q[n-1];
  
  for(int i=1;i<=n-3;i++){
    if(q[i]==0 && s[i]=='o') q[i+1]=q[i-1];
    if(q[i]==0 && s[i]=='x') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='o') q[i+1]=1-q[i-1];
    if(q[i]==1 && s[i]=='x') q[i+1]=q[i-1];
  }
  ok=true;
  if(q[n-2]==0 && s[n-2]=='o' && q[n-1]!=q[n-3]) ok=false;
  if(q[n-2]==0 && s[n-2]=='x' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='o' && q[n-1]==q[n-3]) ok=false;
  if(q[n-2]==1 && s[n-2]=='x' && q[n-1]!=q[n-3]) ok=false;

  if(q[n-1]==0 && s[n-1]=='o' && q[0]!=q[n-2]) ok=false;
  if(q[n-1]==0 && s[n-1]=='x' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='o' && q[0]==q[n-2]) ok=false;
  if(q[n-1]==1 && s[n-1]=='x' && q[0]!=q[n-2]) ok=false;

  if(ok){
    rep(i,n){
      if(q[i]) cout << "W";
      else cout << "S";
    }
    cout << endl;
    return 0;
  }

  cout << -1 << endl;
}