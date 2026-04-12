#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;

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

void debug_out() { cerr << endl; }

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
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")
#define SZ(x) ((int)(x).size())

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void vprint(vector<ll> A){
    ll L = A.size();
    FOR(i, 0, L){
        if(i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
}

ll N; 
string s; 
VI S;

bool check_around(ll i){
  ll forward = i+1;
  ll prev = i-1;
  if(forward==N) forward = 0;
  if(prev==-1) prev = N-1;
  // last is sheep
  if(S[i]==0){
    if(s[i]=='o'){
      if(S[prev]==S[forward]){
        return true;
      }
    }else{
      if(S[prev]!=S[forward]){
        return true;
      }
    }
  }
  // last is wolf
  else{
    if(s[i]=='o'){
      if(S[prev]!=S[forward]){
        return true;
      }
    }else{
      if(S[prev]==S[forward]){
        return true;
      }
    }
  }
  return false;
}

// 0 sheep
// 1 wolf
string f(ll i, ll j){
  debug(i, j);
  S.resize(N, -1);
  S[0] = i;
  S[1] = j;
  FOR(i, 2, N){
    // i-1 : sheep
    if(S[i-1]==0){
      if(s[i-1]=='o'){
        S[i] = S[i-2];
      }else{
        S[i] = 1 - S[i-2];
      }
    }
    // i-1 : wolf
    else{
      if(s[i-1]=='o'){
        S[i] = 1 - S[i-2];
      }
      else{
        S[i] = S[i-2];
      }
    }
  }
  // debug(S);
  bool is_correct = false;

  if(check_around(N-1) && check_around(0)){
    is_correct = true;
  }
  if(is_correct){
    stringstream ss;
    for(ll f : S){
      if(f==0){
        ss << 'S';
      }else{
        ss << 'W';
      }
    }
    return ss.str();
  }else{
    return "";
  }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    cin >> N;
    cin >> s;

    rep(i, 2){
      rep(j, 2){
        string t = f(i, j);
        if(t.size()!=0){
          p(t);
          return 0;
        }
      }
    }
    p(-1);
    
    return 0;
}