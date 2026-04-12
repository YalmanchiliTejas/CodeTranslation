#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int N, M;
vector < vector<int> > edge(20);
int ans = 0;

int main(){
  cin >> N >> M;
  rep(i, M){
    int a, b; cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int r[N];
  rep(i, N) r[i] = i;
  do{
    if (r[0] != 0) continue;
    bool flag = true;
    rep(i, N-1){
      if (find(begin(edge[r[i]]), end(edge[r[i]]), r[i+1]) == end(edge[r[i]])){
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }while(next_permutation(r, r+N));
  cout << ans << endl;
}
