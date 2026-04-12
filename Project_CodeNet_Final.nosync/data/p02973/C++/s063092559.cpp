#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n; scanf("%d", &n);
  vector<int> a(n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  deque<int> que;
  que.push_back(a[0]);
  for(int i = 1; i < n; i++){
    int now = que.front();
    if(now >= a[i]) que.push_front(a[i]);
    else{
      int id = lower_bound(que.begin(), que.end(), a[i]) - que.begin();
      que[id - 1] = a[i];
    }
  }
  printf("%d\n", int(que.size()));
}