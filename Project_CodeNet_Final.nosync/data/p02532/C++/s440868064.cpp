#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <complex>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#ifndef typeof
#define typeof __typeof__
#endif // typeof
 
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rtr(c, i) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define repby(i, a, b, step) for(typeof(b) i = (a); i < (b); i += (step))
#define repab(i, a, b) repby(i, (a), (b), 1)
#define rep(i, n) repab(i, 0, (n))
#define pb push_back
#define sz(c) int((c).size())

class Robot {
  enum cmd {
    PUSH,
    POP,
    MOVE,
    QUIT,
    SENTINEL,
  };
public:
  Robot(istream &src, ostream &dst) : is(src), os(dst) {
  }

  void init(int n) {
    ctbl[string("push")] = PUSH;
    ctbl[string("pop")] = POP;
    ctbl[string("move")] = MOVE;
    ctbl[string("quit")] = QUIT;

    n++;
    while (n--) {
      sv.pb(stack<char>());
    }
  }

  int push() {
    int p;
    char c;
    is >> p >> c;
    sv[p].push(c);
    return 1;
  }

  int pop() {
    int p;
    is >> p;
    os << sv[p].top() << endl;
    sv[p].pop();
    return 1;
  }

  int move() {
    int p1, p2;
    is >> p1 >> p2;
    sv[p2].push(sv[p1].top());
    sv[p1].pop();
    return 1;
  }

  int exec() {
    string command;
    is >> command;

    cmd c = ctbl[command];

    switch (c) {
    case PUSH: return push();
    case POP: return pop();
    case MOVE: return move();
    case QUIT: return 0;
    }
  }
private:
  istream &is;
  ostream &os;
  vector<stack<char> > sv;
  map<string, cmd> ctbl;
};

int main(int argc, char **argv)
{
  int n;
  Robot r(cin, cout);

  cin >> n;
  r.init(n);

  while (r.exec()) {};

  return 0;
}