#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
#include <limits>
#include <time.h>
#include <cstdint>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
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
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rRep(i,a,b) for(ll i=a;i>=b;i--)
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

ll A[200007],dp[5][200007];

int main(){
  ll N;
  cin >> N;
  rep(i,N){
    cin >> A[i];
  }
  if(N%2==0){
    dp[0][0]=A[0];
    dp[0][1]=A[0];
    dp[1][1]=A[1];
    Rep(i,2,N){
      if(i%2==0){
        dp[0][i]=dp[0][i-2]+A[i];
        dp[1][i]=dp[1][i-1];
      }
      else{
        dp[0][i]=dp[0][i-1];
        dp[1][i]=max(dp[1][i-1]+A[i],dp[0][i-3]+A[i]);
      }
      //cout << dp[0][i] << " " << dp[1][i] << endl;
    }
    cout << max(dp[1][N-1],dp[0][N-2]) << endl;
  }
  else{
    dp[0][0]=A[0];
    dp[0][1]=A[0];
    dp[0][2]=A[0]+A[2];
    dp[1][1]=A[1];
    dp[1][2]=A[1];
    dp[2][2]=A[2];
    Rep(i,3,N){
      if(i%2==0){
        dp[0][i]=dp[0][i-2]+A[i];
        dp[1][i]=dp[1][i-1];
        dp[2][i]=max(dp[2][i-1]+A[i],max(dp[1][i-3]+A[i],dp[0][i-4]+A[i]));
      }
      else{
        dp[0][i]=dp[0][i-1];
        dp[1][i]=max(dp[1][i-1]+A[i],dp[0][i-2]+A[i]);
        dp[2][i]=dp[2][i-1];
      }
      //cout << dp[0][i] << " " << dp[1][i] << endl;
    }
    cout << max(dp[2][N-1],max(dp[1][N-2],dp[0][N-3])) << endl;
  }
}