#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
typedef pair<ll, ll> pll;
typedef double rl;

typedef pii int2;
typedef tuple<int, int, int>           int3;
typedef tuple<int, int, int, int>      int4;
typedef tuple<int, int, int, int, int> int5;

typedef pll ll2;
typedef tuple<ll, ll, ll>         ll3;
typedef tuple<ll, ll, ll, ll>     ll4;
typedef tuple<ll, ll, ll, ll, ll> ll5;

#define g0(x) get<0>(x)
#define g1(x) get<1>(x)
#define g2(x) get<2>(x)
#define g3(x) get<3>(x)
#define g4(x) get<4>(x)

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<pll> vll_ll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vll_ll> vvll_ll;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define xx first
#define yy second

#define FOR(i,N) for(int i=0; i<N; i++)

#define popc __builtin_popcountll
// #define popc __builtin_popcount

template<typename A>
string to_string(A* ptr)
{
    stringstream ss; ss << "0x" << std::setw(16) << std::setfill ('0') << std::hex << (uint64_t)(uintptr_t)ptr;
    return ss.str();
}

string to_string(char c)
{
    return ((string)"'"+c)+ "'";
}

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

#if !ONLINE_JUDGE && 1
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

ll N, X, M;

ll f(ll A)
{
    ll R=A*A;
    return R%M;
}

const int MAXM=1e5+99;
ll A[MAXM];
ll sumA[MAXM];
ll Aidx[MAXM];

ll solve()
{
    for(int i=0; i<M; i++) Aidx[i]=0;

    sumA[0]=0;

    A[1]=X;
    sumA[1]=X;
    Aidx[X]=1;

    ll AA=X;

    ll result=X;

    for(ll i=2; i<=N; i++)
    {
        AA=f(AA);
        if(Aidx[AA]==0)
        {
            A[i]=AA;
            sumA[i]=sumA[i-1]+AA;
            Aidx[AA]=i;

            result+=AA;
        }
        else
        {
            ll j=Aidx[AA];
            ll T=i-j;

            ll k=(N-i+1)/T;

            ll sum_period=sumA[i-1]-sumA[j-1];

            ll result_pre=sumA[i-1];

            ll sum_new=result_pre+sum_period*k;
            ll i_new=i-1+k*T;

            for(ll ii=i_new+1, ii2=j; ii<=N; ii++, ii2++)
            {
                sum_new+=A[ii2];
            }

            return sum_new;
        }
    }

    return result;
}

int main()
{
#if !ONLINE_JUDGE && 0
    freopen("F.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
#if 0
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#endif

    int TT;
#if 0
    cin >> TT;
#else
    TT=1;
#endif
    for(int ttt=0; ttt<TT; ttt++)
    {
        cin >> N >> X >> M;
        cout << solve();
    }

    return 0;
}
