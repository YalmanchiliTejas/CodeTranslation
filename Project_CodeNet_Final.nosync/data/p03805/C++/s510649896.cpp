#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int n, m, a, b;
vector<int> to[10];
vector<int> arr;


int main(){
  cin >> n >> m;

  rep(i, m){
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i, n){
    arr.push_back(i);
  }
  int ans=0;
  do {
    bool flag=true;
    rep(i, n-1){
      if(find(to[arr[i]].begin(), to[arr[i]].end(), arr[i+1])==to[arr[i]].end()){
        flag=false;
        break;
      }
    }
    if(flag)ans++;
  } while (next_permutation(arr.begin()+1, arr.end()));
  cout << ans << endl;
  return 0;
}
