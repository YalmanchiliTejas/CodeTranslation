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

ll A[110][110];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, M, K;
    cin >> N >> M >> K;

    VI D(M);
    map<ll, ll> inv;
    rep(i, M){
      cin>>D[i];
      D[i]--;
      inv[D[i]] = i;
    }
    debug(D);
    debug(inv);

    map<ll, ll> mp;
    for(ll d : D){
      mp[d] = 1;
    }

    rep(i, N){
      rep(j, K){
        cin >> A[i][j];
        A[i][j]--;
      }
    }

    VI dp(1<<M, inf);
    dp[(1<<M)-1] = 0;
    queue<ll> que;
    que.push((1<<M)-1);
    while(!que.empty()){
      ll flag = que.front(); que.pop();
      ll n = dp[flag];

      // k番目の扉を選ばせる
      rep(k, K){
        ll next = 0; // 16人の行き先
        
        // 各部屋にいる人を動かす
        rep(i, M){
          if(flag>>i&1){
            ll room_id = D[i];
            ll to = A[room_id][k];
            if(mp[to]==1){
              // また暗い部屋に行く
              // debug(bitset<16>(next));
              next = next | (1LL<<inv[to]);
              // debug(to, inv[to]);
              // debug(bitset<16>(next));
            }
          }
        }

        if(dp.at(next)==inf){
        // if(dp[next]==inf){
          dp[next] = n+1;
          que.push(next);
        }
      }
    }
    p(dp[0]);
    
    return 0;
}
