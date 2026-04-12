#include<stdio.h>
#include<map>
#include<vector>

using namespace std;

int ar[100005];
map<int,vector<int>>ma;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
    ma[-ar[i]].push_back(i);
    map<int,vector<int>>::iterator p = ma.upper_bound(-ar[i]);
    if (p != ma.end()) {
      ar[p->second[p->second.size() - 1]] = -1;
      p->second.pop_back();
      if (p->second.size() == 0) {
        ma.erase(p);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ar[i] != -1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}