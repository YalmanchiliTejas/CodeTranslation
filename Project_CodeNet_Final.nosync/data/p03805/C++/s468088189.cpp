#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n,m;
  cin >> n >> m;
  bool graph[10][10] = {};
  vi data(n);
  rep(i,n) data.at(i) = i;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1] = true;
    graph[b-1][a-1] = true;
  }
  int cnt = 0;
  do{
    if(data.at(0) != 0) continue;
    bool flag = true;
    for(int i=0;i<n-1;i++){
      if(!graph[data[i]][data[i+1]]) flag = false;
    }
    cnt += flag;
  }while(next_permutation(data.begin(), data.end()));
  cout << cnt << endl;
}