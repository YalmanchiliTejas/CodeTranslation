#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[60], a[60];

long long dfs(int level, long long x) {
  if(a[level] <= x) return p[level];
  if(x <= 1) return 0;
  if(a[level-1] + 1 >= x) return dfs(level-1, x - 1);
  return p[level-1] + 1 + dfs(level-1, x - a[level-1] - 2);
}

int main(){
  long long n, x;
  
  cin >> n >> x;
  
  p[0] = 1;
  a[0] = 1;
  for(int i=0;i<59;i++) p[i+1] = p[i] * 2 + 1;
  for(int i=0;i<59;i++) a[i+1] = a[i] * 2 + 3;
  
  cout << dfs(n, x) << endl;
}




