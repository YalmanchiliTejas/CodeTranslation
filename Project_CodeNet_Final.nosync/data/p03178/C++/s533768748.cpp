#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
#define p_yes() p("YES")
#define p_no() p("NO")
#define SZ(x) ((int)(x).size())
#define SORT(A) sort(ALL(A))
#define RSORT(A) sort(ALL(A), greater<ll>())
#define MP make_pair

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double PI = acos(-1);

// i
// j : smaller flag
ll dp[100050][2][105];

ll ctoi(char c){
  ll v = c-'0';
  return v;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    string s; cin >> s;
    ll L = s.size();
    ll D; cin>>D;

    ll keta = L-1;
    ll i = L-keta-1;
    // debug(keta, i);
    // p(s[i]);
    ll v = ctoi(s[i]);
    // debug(v);
    dp[keta][0][v%D] += 1; // exact
    // debug(dp[keta][0][v%D], keta, v%D);
    
    rep(k, v){
      dp[keta][1][k%D] += 1;
    }

    // debug(dp[1][0][3]);
    // debug(dp[1][0][2]);
    // debug(dp[1][1][2]);
    // debug(dp[1][1][1]);
    // debug(dp[1][1][2]);
    // return 0;

    // for(int i=L-1; i>=0; i--){
    for(int i=L-2; i>=0; i--){
      // i : 桁 (0-index)
      // char c = s[i];
      char c = s.at(L-i-1);
      ll v = ctoi(c);

      // mod
      rep(m, D){
        rep(k, 10){
          // smaller to smaller
          dp[i][1][(m+k)%D] += dp[i+1][1][m];
          dp[i][1][(m+k)%D] %= mod;
        }

        rep(k, v){
          // exact to smaller
          dp[i][1][(m+k)%D] += dp[i+1][0][m];
          dp[i][1][(m+k)%D] %= mod;
        }

        // exact to exact
        ll k = v;
        dp[i][0][(m+k)%D] += dp[i+1][0][m];
        dp[i][0][(m+k)%D] %= mod;
      }
    }

    ll sum = dp[0][0][0] + dp[0][1][0];
    sum -= 1;
    if(sum<0) sum+=mod;
    sum %= mod;
    p(sum);



    
    return 0;
}