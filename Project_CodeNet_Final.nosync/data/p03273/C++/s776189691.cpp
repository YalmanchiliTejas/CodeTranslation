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
int h, w;
vector<string> vec;

int main(int argc, char const* argv[])
{
  cin >> h >> w;
  for(int i = 0; i < h; i++){
    string s;
    cin >> s;
    vec.pb(s);
  }
  set<int> wvec;
  for(int i = 0; i < h; i++){
    bool sh = false;
    for(int j = 0; j < w; j++){
      if(vec[i][j] == '#'){
        sh = true;
        break;
      }
    }
    if(sh)wvec.insert(i);
  }
  set<int> hvec;
  for(int i = 0; i < w; i++){
    bool sh = false;
    for(int j = 0; j < h; j++){
      if(vec[j][i] == '#'){
        sh = true;
        break;
      }
    }
    if(sh)hvec.insert(i);
  }
  for(int i = 0; i < h; i++){
    if(wvec.find(i) == wvec.end())continue;
    for(int j = 0; j < w; j++){
      if(hvec.find(j) == hvec.end())continue;
      cout << vec[i][j];
    }
    cout << endl;
  }
	return 0;
}
