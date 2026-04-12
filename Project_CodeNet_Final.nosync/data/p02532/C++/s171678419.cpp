#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define rrep(i,n) for(int i=n-1;0<=i;--i)
#define rRep(i,n) for(int i=n;0<i;--i)
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define scani(a) scanf("%d",&a)
#define scanr(a) scanf("%lf",&a)
#define scans(s) scanf("%s",s)
#define printi(a) printf("%d",a)
#define printr(a) printf("%lf",a)
#define prints(s) printf("%s",s)
#define is_odd(n) (n&1)
#define is_even(n) ((n+1)&1)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define all(x) x.begin(), x.end()
#define EPS 1e-8
#define INF 1e8
#define PI acos(-1.0)

typedef double Real;
typedef int Int;
typedef vector<Int> vi;
typedef vector<vector<Int> > vvi;
typedef pair<Int,Int> pii;

inline Real sr(Real a) {return sqrt(max(a, (Real)0));}
template <typename T> inline T sq(T a) {return a * a;}
const vi dy = {-1, 0, 1, 0}, dx = {0, -1, 0, 1};
vector<string> split(const string &s, char d) {vector<string> r;stringstream t(s);string x;while(getline(t,x,d))if(!x.empty())r.push_back(x);return r;}

Int N;
vector<vector<char> > ss;

void pop(Int idx)
{
  cout << ss[idx].back() << endl;
  ss[idx].pop_back();
}

void push(Int idx, char c)
{
  ss[idx].push_back(c);
}

void move(Int fr, Int to)
{
  ss[to].push_back(ss[fr].back());
  ss[fr].pop_back();
}

void solve()
{
  cin >> N;
  ss.resize(N);

  while(!cin.eof())
  {
    string command; cin >> command;
    if(command == "quit") break;

    if(command == "pop")
    {
      Int i; cin >> i;
      pop(i-1);
    }
    else if(command == "push")
    {
      Int i; cin >> i;
      char c; cin >> c;
      push(i-1, c);
    }
    else if(command == "move")
    {
      Int i, j; cin >> i >> j;
      move(i-1, j-1);
    }
  } 
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

  solve();

  return 0;
}