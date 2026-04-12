#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

int main(int argc, char const* argv[])
{
  string s;
  cin >> s;
  for(int i = 0; i + 1 < s.size(); i++){
    if(s[i] == 'A' && s[i + 1] == 'C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
	return 0;
}
