#include <cstdio>
#include <cstdint>
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
#include <bitset>

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

bool is_sheep0[4] = {true, true, false, false};
bool is_sheep1[4] = {true, false, true, false};
vector<bool> sheep;
int n;
string s;

bool check(){
  if(((sheep[n - 1] && s[n - 1] == 'o') || (!sheep[n - 1] && s[n - 1] == 'x')) && sheep[n - 2] != sheep[0])return false;
  if(((sheep[n - 1] && s[n - 1] == 'x') || (!sheep[n - 1] && s[n - 1] == 'o')) && sheep[n - 2] == sheep[0])return false;
  if(((sheep[0] && s[0] == 'o') || (!sheep[0] && s[0] == 'x')) && sheep[n - 1] != sheep[1])return false;
  if(((sheep[0] && s[0] == 'x') || (!sheep[0] && s[0] == 'o')) && sheep[n - 1] == sheep[1])return false;
  return true;
}

void dump() {
  for(int i = 0; i < n; i++){
    if(sheep[i])cout << 'S';
    else cout << 'W';
  }
  cout << endl;
}

int main(int argc, char const* argv[])
{
  cin >> n;
  cin >> s;
  sheep = vector<bool>(n, false);
  for(int i = 0; i < 4; i++){
    sheep[0] = is_sheep0[i];
    sheep[1] = is_sheep1[i];
    for(int j = 1; j < n - 1; j++){
      if((sheep[j] && s[j] == 'o') || (!sheep[j] && s[j] == 'x')){
        sheep[j + 1] = sheep[j - 1];
      }else{
        sheep[j + 1] = !sheep[j - 1];
      }
    }
    if(check()){
      dump();
      return 0;
    }
  }
  cout << - 1 << endl;
	return 0;
}
