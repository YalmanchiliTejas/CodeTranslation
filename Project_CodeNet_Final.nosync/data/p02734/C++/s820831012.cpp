#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "
#define A(a, i) #a "[" #i " =", i, "] =", a[i], " "

const int MXN = 3005;
int t[MXN];
int s;

LL res = 0;


int mod = 998244353;
int ple[2][MXN][MXN];


void clear(int r, int idx)
  {
  FOR(i, 0, s)ple[r][idx][i] = 0;
  ple[r][idx][0] = 1;
  }

void add(int r, int idx, int val, int off)
  {
  FOR(i, 0, s)ple[r][idx][i] = ple[r][idx+off][i];

  FORD(i, s, val)
    {
    ple[r][idx][i] += ple[r][idx][i-val];
    if(ple[r][idx][i] >= mod)ple[r][idx][i] -= mod;
    }
  }

LL sum_1[MXN];
LL sum_2[MXN];


void go(int a, int b)
  {
  if(a == b)
    {
    if(t[a] == s)res += 1;
    return;
    }
  if(a > b)return;

  int mid = (a + b) / 2;
  // a .. mid w lewej
  // mid+1 .. b w prawej

  clear(1, mid);
  FOR(i, mid+1, b)
    {
    add(1, i, t[i], -1);
    }

  clear(0, mid+1);
  FORD(i, mid, a)
    {
    add(0, i, t[i], 1);
    }

  FOR(i, 0, s)sum_1[i] = sum_2[i] = 0;

  FOR(i, a, mid)
    {
    FOR(su, 0, s)sum_1[su] += ple[0][i][su];
    }
  FOR(j, mid+1, b)
    {
    FOR(su, 0, s)sum_2[su] += ple[1][j][su];
    }
  FOR(i, 0, s)
    {
    sum_1[i] %= mod;
    sum_2[i] %= mod;
    }

  FOR(par_s, 0, s)
    res += (LL)sum_1[par_s] * sum_2[s - par_s] % mod;
  res %= mod;

  go(a, mid);
  go(mid+1, b);

  }

int main()
{
  int n;
  scanf("%d%d", &n, &s);
//  n = s = 3000;
  FOR(i, 1, n)
    {
    scanf("%d", &t[i]);
//    t[i] = 1;
    }

  go(1, n);
  res %= mod;
  cout << res << endl;
}
