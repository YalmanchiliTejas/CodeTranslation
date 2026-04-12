#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int all = 0;
int check(vvi &root, int current, int checked){
  if(checked == all) return 1;
  int total = 0;
  for(int num : root[current]){
    if(!(checked & (1 << num))){
      checked |= (1 << num);
      total += check(root, num, checked);
      checked &= ~(1 << num);
    }
  }
  return total;
}
int main(){
  int n,m;
  cin >> n >> m;
  vvi root(n);
  rep(i, m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  rep(i, n){
    all++;
    all <<= 1;
  }
  all >>= 1;
  int checked = 1;
  cout << check(root, 0, checked) << endl;
}