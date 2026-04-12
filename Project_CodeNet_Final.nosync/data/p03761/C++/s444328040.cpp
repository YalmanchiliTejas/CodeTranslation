#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v(n);
  vector<map<char, int>> count(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for(auto a : v[i]){
      count[i][a]++;
    }
  }

  map<char, int> res;
  for(auto a : count[0]){
    res[a.first] += a.second;
  }

  for(auto a = count.begin() + 1; a < count.end(); a++){
    map<char, int> tmp;
    for(auto b : *a){
      tmp[b.first] = b.second;
    }
    for(auto b : res){
      // print(b);
      res[b.first] = min(b.second, tmp[b.first]);
    }
  }

  string s = "";
  for(auto a : res){
    for (int i = 0; i < a.second; i++) {
      s += a.first;
    }
  }
  cout << s << endl;
}
