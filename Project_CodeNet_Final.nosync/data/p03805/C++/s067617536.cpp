#include <bits/stdc++.h>
 
using namespace std ;
typedef long long ll;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll ;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<vll> vvll;
typedef vector<str> vstr;
typedef vector<pii> vpii ;
typedef vector<pll> vpll ;
 
#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define CHI 1000000000000000003
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define TS to_string
#define NP next_permutation
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)
 
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数
 
void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}

void solve(vvint edge,int n,int m){
  ll ans=0;
  vint verticle(10);
  REP(i,n){
    verticle[i]=i+1;
  }
  do{
    bool check=true;
    REP(i,n-1){
      if(edge[verticle[i]][verticle[i+1]]!=1){
        check=false;
      }
    }
    if(check){
      ans+=1;
    }
  }while(next_permutation(verticle.begin()+1,verticle.begin()+n));
  cout << ans << endl;
}

int main(){
  int n,m;
  cin >> n;
  cin >> m;
  vvint edge(30,vint(30,0));
  REP(i,m){
    int v1,v2;
    cin >> v1;
    cin >> v2;
    edge[v1][v2]=1;
    edge[v2][v1]=1;
  }
  solve(edge,n,m);
}