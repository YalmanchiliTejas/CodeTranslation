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
//-----------------------------------------




















//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n ;
  cin >> n ;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  priority_queue<ll, vector<ll>, less<ll>> que2;
  REP(i,n){
    ll a ;
    cin >> a ;
    que.push(a) ;
    que2.push(a) ;
  }
  deque<ll> deq ;
  int cnt = 0 ;
  deq.PB(que.top()) ;
  que.pop() ;
  cnt++ ;
  while(cnt<n){
    if(cnt==n-1){
      ll k = que.top() ;
      if(abs(deq.front()-k)>=abs(deq.back()-k)){
        deq.push_front(k) ;
      }
      else{
        cnt++ ;
        deq.push_back(k) ;
      }
      break ;
    }
      
    if(cnt%4==1){
      deq.push_front(que2.top()) ;
      que2.pop() ;
      cnt++ ;
    }
    else if(cnt%4==2){
      deq.push_back(que2.top()) ;
      que2.pop() ;
      cnt++ ;
    }
    else if(cnt%4==3){
      deq.push_front(que.top()) ;
      que.pop() ;
      cnt++ ;
    }
    else{
      deq.push_back(que.top()) ;
      que.pop() ;
      cnt++ ;
    }
  }
  
  vll num ;
  auto itr = deq.begin() ;
  while(itr !=deq.end()){
    num.PB((*itr)) ;
    itr++ ;
  }
  ll ans = 0;
  REP(i,n-1){
    ans += abs(num[i]-num[i+1]) ;
  }
  cout << ans <<endl ;
      
  
  
  
  
  return 0 ;


}


