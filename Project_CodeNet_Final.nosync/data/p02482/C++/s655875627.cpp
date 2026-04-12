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

int main(int argc, char **argv)
{
  int a, b;

  cin >> a >> b;
  if (a < b)
    cout << "a < b";
  else if (a > b)
    cout << "a > b";
  else
    cout << "a == b";

  cout << endl;

  return 0;
}