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

int n,m,s,t,a,b,c;
vii adj[100005];
// LL S[100005],T[100005];
vector<LL> S, T;
LL MOD = 1e9 + 7;
LL finish[100005],start[100005];

void sp(int st, vector<LL> &dist)
{
  fill(ALL(dist),-1);
  priority_queue<pair<LL,int>> pq;
  pq.push(mp(0,st));
  while (!pq.empty())
  {
    LL jarak = -pq.top().fi;
    int now = pq.top().se;
    pq.pop();
    if (dist[now] != -1) continue;
    dist[now] = jarak;
    VALUE(now);
    VALUE(jarak);
    REP(i,SIZE(adj[now]))
    {
      pq.push(mp(-jarak-adj[now][i].se,adj[now][i].fi));
    }
  }
}

LL jahja_finish(int now)
{
  if (now == t) return 1;
  LL &ret = finish[now];
  if (ret >= 0) return ret;
  ret = 0;
  REP(i,SIZE(adj[now]))
  {
    if (S[now] + adj[now][i].se == S[adj[now][i].fi])
      ret += jahja_finish(adj[now][i].fi);
  }
  ret %= MOD;
  return ret;
}

LL jahja_start(int now)
{
  if (now == s) return 1;
  LL &ret = start[now];
  if (ret >= 0) return ret;
  ret = 0;
  REP(i,SIZE(adj[now]))
  {
    if (T[now] + adj[now][i].se == T[adj[now][i].fi])
      ret += jahja_start(adj[now][i].fi);
  }
  ret %= MOD;
  return ret;
}

int main()
{
  scanf("%d %d",&n,&m);
  S.resize(n + 5);
  T.resize(n + 5);
  scanf("%d %d",&s,&t); --s; --t;
  TC(m)
  {
    scanf("%d %d %d",&a,&b,&c);
    --a; --b;
    adj[a].pb(mp(b,c));
    adj[b].pb(mp(a,c));
  }
  sp(s,S);
  sp(t,T);
  RESET(finish,-1);
  RESET(start,-1);
  LL risan = jahja_finish(s) * jahja_start(t) % MOD;
  LL risan2 = 0;
  REP(i,n)
  {
    if (S[i] + T[i] == S[t] && S[i] * 2 == S[t])
    {
      LL now = jahja_finish(i) * jahja_start(i) % MOD;
      now = now * now % MOD;
      risan2 = (risan2 + now) % MOD;
    }
  }
  REP(i,n) REP(j,SIZE(adj[i]))
  {
    int x = adj[i][j].fi;
    if (S[i] + T[x] + adj[i][j].se == S[t] && S[i] * 2 < S[t] && S[x] * 2 > S[t])
    {
      LL now = jahja_finish(x) * jahja_start(i) % MOD;
      now = now * now % MOD;
      risan2 = (risan2 + now) % MOD;
    }
  }
  risan = (risan - risan2 + MOD) % MOD;
  printf("%lld\n",risan);
  return 0;
}









