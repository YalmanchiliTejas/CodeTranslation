#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
#endif
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;
using PII = pair<ll, ll>;

// tourist set
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// tourist set end

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<'\n'
#define p2(s, t) cout << (s) << " " << (t) << '\n'
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << '\n'
#define SZ(x) ((int)(x).size())
#define SORT(A) sort(ALL(A))
#define RSORT(A) sort(ALL(A), greater<ll>())
#define MP make_pair
#define p_yes() p("Yes")
#define p_no() p("No")

ll SUM(VI& V){
  return accumulate(ALL(V), 0LL);
}

ll MIN(VI& V){return *min_element(ALL(V));}
ll MAX(VI& V){return *max_element(ALL(V));}

void print_vector(VI& V){
  ll n = V.size();
  rep(i, n){
    if(i) cout << ' ';
    cout << V[i];
  }
  cout << endl;
}

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

// long double
using ld = long double;
#define EPS (1e-14)
#define equals(a,b) (fabs((a)-(b)) < EPS)

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double PI = acos(-1);

ll dp[200010][2][3];
void reset(){
  rep(i,200010) rep(j,2) rep(k,3) dp[i][j][k] = -inf;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N; 
    cin>>N;

    VI A(N+10);
    rep(i, N) cin >> A[i];

    if(N==2){
      ll ans = max(A[0],A[1]);
      p(ans);
      return 0;
    }
    
    reset();
    dp[0][0][0]=0;
    dp[0][1][0]=A[0];

    dp[2][1][1]=A[2]; // いきなり大ジャンプ

    rep(i,N){
      rep(j,2){
        rep(k,3){
          if(j==0){
            if(k!=2){
              // 大ジャンプ可能
              // 1歩先を選ばない(大ジャンプ)
              chmax(dp[i+1][0][k+1], dp[i][j][k] + 0);
              // 2歩先を選ぶ(大ジャンプ)
              chmax(dp[i+2][1][k+1], dp[i][j][k] + A[i+2]);
            }
            // 1歩先を選ぶ
            chmax(dp[i+1][1][k], dp[i][j][k] + A[i+1]);   
          }
          else{
            // j==1 (選んでる)
            if(k!=2){
              // 大ジャンプ可能
              // 3歩先を選ぶ(大ジャンプ)
              chmax(dp[i+3][1][k+1], dp[i][j][k] + A[i+3]);
            }
            // 1歩先を選ばない
            chmax(dp[i+1][0][k], dp[i][j][k] + 0);
            // 2歩先を選ぶ
            chmax(dp[i+2][1][k], dp[i][j][k] + A[i+2]);            
          }
        }
      }
    }
    rep(i,4){
      debug(i);
      debug(dp[i][0][0]);
      debug(dp[i][0][1]);
      debug(dp[i][1][0]);
      debug(dp[i][1][1]);
    }

    ll ans = -1;
    if(N%2==0){
      VI A;
      A.push_back(dp[N-1][1][0]);
      A.push_back(dp[N-1][1][1]);
      A.push_back(dp[N-1][0][0]);
      
      ans = MAX(A);
    }
    else{
      VI A;
      A.push_back(dp[N-1][1][1]);
      A.push_back(dp[N-1][1][2]);
      A.push_back(dp[N-1][0][1]);
      A.push_back(dp[N-1][0][0]);
      debug(A);
      ans = MAX(A);
      // ll a = dp[N-3][1][0];
      // ll b = dp[N-2][1][0];
      // ll c = dp[N-1][1][1];
      // ans = max({a,b,c});
    }
    p(ans);
    
    return 0;
}