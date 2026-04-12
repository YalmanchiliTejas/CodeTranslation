#include<bits/stdc++.h>
using namespace std;

int ans, n, m, a, b, v[10];
bool pass[10][10];

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &a, &b); a--; b--;
    pass[a][b] = pass[b][a] = true;
  }
  for(int i = 0; i < n; i++) v[i] = i;
  do{
    bool ok = true;
    for(int i = 1; i < n; i++) ok &= pass[v[i-1]][v[i]];
    ans += ok;
  }while(next_permutation(v+1, v+n));
  printf("%d\n", ans);
}
