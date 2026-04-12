//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}

//end of jonathanirvings' template v3.0.3 (BETA)

LL dpS[3005][3005];
LL C[3005][3005];
LL par[3005];
LL m;
int n;
LL dua[3005];
LL dpmagic[3005][3005];
LL duadua[3005];

LL S(int n, int k)
{
  // debug("%d %d\n",n,k);
  if (n == 0 && k == 0) return 1;
  if (n == 0 || k == 0) return 0;
  LL &ret = dpS[n][k];
  // debug("%d %d\n",n,k);
  if (ret >= 0) return ret;
  return ret = (k * S(n - 1, k) + S(n - 1, k - 1)) % m;
}

LL p(LL a,LL b)
{
  if (b == 0) return 1;
  LL ret = p(a,b/2);
  LL ret2 = ret * ret;
  if (b % 2 == 0) return ret2;
  return ret2 * a;
}

LL powmod(LL a,LL b)
{
  if (b == 0) return 1;
  LL ret = powmod(a,b/2);
  LL ret2 = ret * ret % m;
  if (b % 2 == 0) return ret2;
  return ret2 * a % m;
}

// stirling at most n
LL magic(int n, int k)
{
  return S(n+1,k+1);
  LL &ret = dpmagic[n][k];
  if (ret >= 0) return ret;
  // if (n == k) return ret = S(n,k);
  // return ret = S(n,k) + magic(n-1,k);
  // LL ret = 0;
  ret = 0;
  FORN(i,k,n) ret = (ret + C[n][i] * S(i,k)) % m;
  return ret;
}

void precompute()
{
  dua[0] = 1;
  FORN(i,1,n)
  {
    dua[i] = (dua[i-1] * 2) % m;
  }
  RESET(dpS,-1);
  RESET(dpmagic,-1);
  FORN(i,0,n)
  {
    par[i] = 0;
    FORN(j,0,i)
    {
      par[i] += S(i,j);
    }
  }
  FORN(i,0,n)
  {
    C[i][0] = C[i][i] = 1;
    FOR(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % m;
  }
  duadua[0] = 2;
  FORN(i,1,n)
  {
    duadua[i] = SQR(duadua[i-1]) % m;
  }
}

int main()
{
  while (scanf("%d %lld",&n,&m) != EOF)
  {
    // VALUE(powmod(2,p(2,50)));
    VALUE(powmod(10, 25));
    precompute();
    LL risan = 0;
    FORN(j,0,n) // yang salah
    {
      LL tempall = 0;
      FORN(num_par,0,j)
      {
        LL temp = powmod(powmod(2,n-j),num_par) * magic(j, num_par) % m;
        // temp = (temp * powmod(2,p(2,n-j))) % m;
        temp = (temp * duadua[n-j]) % m;
        tempall = (tempall + temp) % m;
        // debug("%d %d : %lld\n", j, num_par, temp);
      }
      // LL tempall = powmod(2,p(2,n-j));
      // FORN(k,1,j) // yang keluar sekali
      // {
      //   LL temp = 0;
      //   FORN(num_par,1,k)
      //   {
      //     temp = (temp + S(k, num_par) * powmod(powmod(2,n-j),num_par)) % m;
      //   }
      //   temp = (temp * powmod(2,p(2,n-j))) % m;
      //   temp = (temp * C[j][k]) % m;
      //   tempall = (tempall + temp) % m;
      // }
      // debug("%d : %lld\n", j, tempall);
      tempall = (tempall * C[n][j]) % m;
      if (j % 2 == 0) risan = (risan + tempall) % m;
      else risan = (risan - tempall) % m;
    }
    if (risan < 0) risan += m;
    printf("%lld\n",risan);
  }
  return 0;
}









