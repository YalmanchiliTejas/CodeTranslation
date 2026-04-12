#include <cstdio>
#include <vector>

std::vector<int> e[100000];

int solve(int a, int p){
  int c=0;
  for(auto b: e[a]){
    if(b == p) continue;
    int x = solve(b, a);
    if(x<0) return -1;
    if(x==0){
      if(c) return -1;
      c = 1;
    }
  }
  return c;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i=0;i<n-1;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    e[a-1].push_back(b-1);
    e[b-1].push_back(a-1);
  }
  if(solve(0, -1) == 1) puts("Second");
  else puts("First");
  return 0;
}