#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>

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
int al[26];

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  string s;
  fill(al, al + 26, inf);
  for(int i = 0; i < n; i++){
    cin >> s;
    vector<int> vec = vector<int>(26, 0);
    for(char c: s){
      vec[c - 'a']++;
    }
    for(int i = 0; i < 26; i++){
      al[i] = min(al[i], vec[i]);
    }
  }
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < al[i]; j++){
      cout << char('a' + i);
    }
  }
  cout << endl;
	return 0;
}
