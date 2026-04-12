#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <numeric>

#define rep(i,n) for(int i = 0;i < (n);i++)
#define repp(i,j, n) for(int i = (j);i < (n);i++)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define INF 1e9

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pair<int, int> > vpi;
typedef vector<pair<ll, ll> > vpl;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vvi s(n, vi(26, 0));
  rep(i, n){
    string str;
    cin >> str;
    rep(j, (int)(str.length())){
      s[i][(int)str[j]-(int)'a']++;
    }
  }
  rep(i, 26){
    int min_count = 100;
    rep(j, n){
      min_count = min(s[j][i], min_count);
    }
    rep(k, min_count) cout << (char)((int)'a'+i);
  }
  cout << endl;
  return 0;
}
