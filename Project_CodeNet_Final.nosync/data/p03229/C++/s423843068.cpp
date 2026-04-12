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
#define pb(s) push_back(s)
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

ll que_to_answer(deque<ll> que){
  debug(que);
  // to vector
  VI A;
  for(ll a : que){
    A.push_back(a);
  }
  ll L = A.size();
  ll sum = 0;
  rep(i, L-1){
    ll diff = abs(A[i] - A[i+1]);
    sum += diff;
  }
  return sum;
}

ll M_or_W(VI A, ll offset){
  ll N = A.size();
  
  priority_queue<ll, vector<ll>, greater<ll>> pq_A; // 昇順
  priority_queue<ll> pq_B; // 降順
  for(ll a : A){
    pq_A.push(a);
    pq_B.push(a);
  }

  deque<ll> que;
  
  // offset = 0 : W
  // offset = 1 : M
  debug(offset);

  if(offset==0){
    // 中央に最大
    ll v = pq_B.top(); pq_B.pop();
    que.push_back(v);
  }else{
    // 中央に最小
    ll v = pq_A.top(); pq_A.pop();
    que.push_back(v);
  }
  // que.push_back(A[N/2]);

  rep(i, N/2){
    if(que.size()==N) break;
    if(i%2!=offset){
      // big
      que.push_front(pq_B.top()); pq_B.pop();
      que.push_back(pq_B.top()); pq_B.pop();
    }
    else 
    {
      // small
      que.push_front(pq_A.top()); pq_A.pop();
      que.push_back(pq_A.top()); pq_A.pop();
    }
    debug(i);
    debug(que);
    
  }
  ll candidate0 = que_to_answer(que);
  return candidate0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N; 
    cin >> N;

    VI A(N);
    rep(i, N){
        cin >> A.at(i);
    }
    sort(ALL(A)); // 昇順
    auto B = A;
    sort(ALL(B), greater<ll>()); // 降順
    debug(A);
    debug(B);

    if(N%2==0){
      // N型
      // 係数２
      deque<ll> que;
      ll L = N-2;
      rep(i, L/2){
        que.push_back(B[i]); // 大
        que.push_back(A[i]);
      }
      que.push_back(B[L/2]);
      que.push_front(A[L/2]);
      debug(que);
      ll ans = que_to_answer(que);
      p(ans);
    }
    else{
      // M型
      ll cand0 = M_or_W(A, 0);
      ll cand1 = M_or_W(A, 1);

      ll ans = max(cand0, cand1);
      p(ans);
    }
    
    return 0;
}