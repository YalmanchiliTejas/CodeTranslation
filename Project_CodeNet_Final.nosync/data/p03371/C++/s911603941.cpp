#include <bits/stdc++.h>
#define INF 0x3f3f3f
#define PB push_back
#define F first
#define S second
#define FOR(i,k) for(int i=0; i<k; i++)
#define RFOR(i,k) for(int i=k; i>=0; i--)
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
#define DEBUGV(x) cout<<#x<<": "; for(auto &d:x) cout<<d<<" "; cout<<endl
#define DEBUGM(x) for(auto &p:x) cout<<p.F<<":"<<p.S<<" "; cout<<endl;
#define OUT(x) cout<<(x)<<endl

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<char,int> MC;
typedef map<int,int> MI;
typedef map<string,int> MS;

template<typename T, typename U> void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> void amax(T &x, U y) { if(x < y) x = y; }
VPII neighbors = {{0,1}, {1,0}, {0,-1}, {-1,0}};
PII operator+(PII &l, PII &r) { return {l.F+r.F, l.S+r.S}; }
bool IsValid(PII p, int Y, int X) { 
  return p.F >=0 && p.F < Y && p.S >=0 && p.S < X; }
bool IsPrime(int n) {
  if (n <= 1)  return false;
  if (n <= 3)  return true;
  if (n%2 == 0 || n%3 == 0) return false;
  for (int i=5; i*i<=n; i=i+6)
    if (n%i == 0 || n%(i+2) == 0)
      return false;
  return true;
}

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  float ab = (a + b)/2.0f;

  int res = 0;
  if(ab > c) {
    int minXY = min(x,y);
    x-=minXY;
    y-=minXY;
    res+=minXY*c*2;

    if(a > c*2) {
      res+=x*c*2;
      x=0;
    }
    if(b > c*2) {
      res+=y*c*2;
      y=0;
    }
  }
  res+=x*a+y*b;
  OUT(res);
}