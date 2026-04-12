#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T1, class T2> inline void minup(T1& m, T2 x){ if(m>x) m=static_cast<T2>(x); }
template<class T1, class T2> inline void maxup(T1& m, T2 x){ if(m<x) m=static_cast<T2>(x); }

#define INF 1000000000
#define MOD 1000000009
#define EPS 1E-9

int n;
string cmd;
int pos, pp;
char color;

int main()
{
  cin >> n;
  vector<stack<char> > st(n);

  while(cin >> cmd && cmd != "quit"){
    cin >> pos;  pos -= 1;
    if(cmd == "push"){
      cin >> color;
      st[pos].push(color);
      continue;
    }
    if(cmd == "pop"){
      cout <<  st[pos].top() << endl;
      st[pos].pop();
      continue;
    }
    if(cmd == "move"){
      cin >> pp; pp -= 1;
      st[pp].push(st[pos].top());
      st[pos].pop();
      continue;
    }
  }

  return 0;
}