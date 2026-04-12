#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <limits>
#include <regex>
#include <time.h>
#include <complex>
using namespace std;
using ll=long long;
using pl  = pair<ll,ll>;
using pii  = pair<int,int>;
using ld=long double;
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rRep(i,a,b) for(int i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
ll gcd(ll a,ll b){return (b == 0 ? a : gcd(b, a%b));}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll MOD=1000000007;
constexpr ll INF=1000000011;
constexpr ll MOD2=998244353;
constexpr ll LINF = 1001002003004005006ll;
constexpr ld EPS=10e-8;
template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if (lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if (lhs > rhs) { lhs = rhs; return 1; } return 0; }
template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}
template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}
template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v){
  for(auto i=begin(v); i != end(v); ++i){
    if(i !=begin(v)) os << ' ';
    os << *i;
  }
  return os;
}

string S;
ll dp[2][107][4],K;

int main(){
  cin >> S >> K;
  rep(i,S.size()){
    ll C=ctoi(S[i]);
    if(i==0){
      dp[0][0][1]=1;
      dp[1][0][0]=1;
      dp[1][0][1]=C-1;
      continue;
    }
    if(C==0){
      dp[0][i][0]=dp[0][i-1][0];
      dp[0][i][1]=dp[0][i-1][1];
      dp[0][i][2]=dp[0][i-1][2];
      dp[0][i][3]=dp[0][i-1][3];
      dp[1][i][0]=dp[1][i-1][0];
      dp[1][i][1]=dp[1][i-1][0]*9+dp[1][i-1][1];
      dp[1][i][2]=dp[1][i-1][1]*9+dp[1][i-1][2];
      dp[1][i][3]=dp[1][i-1][2]*9+dp[1][i-1][3];
    }
    else{
      dp[0][i][1]=dp[0][i-1][0];
      dp[0][i][2]=dp[0][i-1][1];
      dp[0][i][3]=dp[0][i-1][2];
      dp[1][i][0]=dp[1][i-1][0];
      dp[1][i][1]=dp[1][i-1][0]*9+dp[1][i-1][1]+dp[0][i-1][0]*(C-1)+dp[0][i-1][1];
      dp[1][i][2]=dp[1][i-1][1]*9+dp[1][i-1][2]+dp[0][i-1][1]*(C-1)+dp[0][i-1][2];
      dp[1][i][3]=dp[1][i-1][2]*9+dp[1][i-1][3]+dp[0][i-1][2]*(C-1)+dp[0][i-1][3];
    }
  }
  cout << dp[0][S.size()-1][K]+dp[1][S.size()-1][K] << endl;
}