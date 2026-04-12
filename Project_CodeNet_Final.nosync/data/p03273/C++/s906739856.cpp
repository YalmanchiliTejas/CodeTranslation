#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
#include<functional>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define erep(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
const int mod = 1e9+7;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;

int main() {
  int h, w;
  cin >> h >> w;
  vs s;
  rep(i, 0, h) {
    string a;
    cin >> a;
    if(count(all(a), '#')) s.push_back(a);
  }

  set<int> st;
  rep(i, 0, w) {
    bool ok = true;
    rep(j, 0, s.size()) {
      if(s[j][i] == '#') ok = false;
    }
    if(ok) st.insert(i);
  }

  rep(i, 0, s.size()) {
    rep(j, 0, w) {
      if(!st.count(j)) cout << s[i][j];
    }
    cout << endl;
  }
}
