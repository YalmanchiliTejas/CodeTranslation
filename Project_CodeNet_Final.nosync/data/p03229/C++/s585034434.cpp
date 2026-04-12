#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

template <class T>
inline bool chmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template <class T>
inline bool chmin(T &a, const T &b) { return b < a ? a = b, true : false; }

int main()
{
  int n;
  cin >> n;
  VI a(n);
  REP(i, n)
      cin >> a[i];
  sort(ALL(a));
  deque<int> q;
  int l=0,r=n;
  q.push_back(a[--r]);

  while ( l<r )
  {
    int x=a[l],y=a[r-1];
    int x1=abs(q.front() - x);
    int x2=abs(q.back()-x);
    int y1=abs(q.front()-y);
    int y2=abs(q.back() - y);
    int mx=max({x1,x2,y1,y2});
    if ( x1==mx ) {
      q.push_front(x); l++;
    }
    else if ( x2==mx ) {
      q.push_back(x); l++;
    }
    else if (y1 == mx)
    {
      q.push_front(y);
      r--;
    }
    else if (y2 == mx)
    {
      q.push_back(y);
      r--;
    }
  }

  LL ans = 0;
  int me = q.front();
  q.pop_front();
  while (q.size())
  {
    // cout << me << ' ';
    ans += abs(q.front() - me);
    me = q.front();
    q.pop_front();
  }
  // cout << me << '\n';

  cout << ans << '\n';
  return 0;
}
