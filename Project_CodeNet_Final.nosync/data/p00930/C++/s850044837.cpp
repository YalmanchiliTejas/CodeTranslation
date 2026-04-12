#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 2000100
#define N 600100

int n, m, qidx;
char str[N];
int minval[MAX], flag[MAX], prefix[MAX];
map<int, int> ridxs;

inline void push_down(int left, int right, int idx){
  if(left == right){
    minval[idx] += flag[idx];
    flag[idx] = 0;
    return;
  }
  
  minval[idx] += flag[idx];
  flag[idx << 1] += flag[idx];
  flag[idx << 1 | 1] += flag[idx];
  flag[idx] = 0;
}

inline void push_up(int left, int right, int idx){
  if(left == right){ push_down(left, right, idx); return; }
  
  int mid = (left + right) >> 1;
  push_down(left, right, idx);
  push_down(left, mid, idx << 1);
  push_down(mid + 1, right, idx << 1 | 1);
  minval[idx] = min(minval[idx << 1], minval[idx << 1 | 1]);
}

inline int query(int start, int end, int left, int right, int idx){
  push_down(left, right, idx);
  if(start <= left && right <= end) return minval[idx];
  
  int mid = (left + right) >> 1, res;
  if(end <= mid) res = query(start, end, left, mid, idx << 1);
  else if(mid < start) res = query(start, end, mid + 1, right, idx << 1 | 1);
  else res = min(query(start, end, left, mid, idx << 1), query(start, end, mid + 1, right, idx << 1 | 1));
  return res;
}

inline void update(int val, int start, int end, int left, int right, int idx){
  push_down(left, right, idx);
  if(start <= left && right <= end){ flag[idx] += val; push_up(left, right, idx); return; }
  
  int mid = (left + right) >> 1;
  if(end <= mid) update(val, start, end, left, mid, idx << 1);
  else if(mid < start) update(val, start, end, mid + 1, right, idx << 1 | 1);
  else{
    update(val, start, end, left, mid, idx << 1);
    update(val, start, end, mid + 1, right, idx << 1 | 1);
  }
  push_up(left, right, idx);
}

inline void build(int left, int right, int idx){
  if(left == right){ minval[idx] = prefix[left]; return; }

  int mid = (left + right) >> 1;
  build(left, mid, idx << 1);
  build(mid + 1, right, idx << 1 | 1);
  minval[idx] = min(minval[idx << 1], minval[idx << 1 | 1]);
}

int main(){
  while(scanf("%d%d", &n, &m) == 2){
    ridxs.clear();
    memset(flag, 0, sizeof(flag));
    
    scanf("%s", str + 1);
    
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (str[i] == '(' ? 1 : -1);
    for(int i = 1; i <= n; i++) if(str[i] == ')') ridxs[i] = 1;
    
    build(1, n, 1);
    
    int ans;
    for(int i = 1; i <= m; i++){
      scanf("%d", &qidx);
      
      if(str[qidx] == '('){
        ridxs[qidx] = 1;
        ans = ridxs.begin()->first;
        ridxs.erase(ridxs.find(ans));
        str[qidx] = ')'; str[ans] = '(';
        if(ans != qidx) update(2, ans, qidx - 1, 1, n, 1);
      }
      else{
        if(query(qidx - 1, qidx - 1, 1, n, 1) < 2) ans = qidx;
        else{
          int lidx = 1, ridx = qidx - 1;
          while(ridx - lidx > 1){
            int mid = (lidx + ridx) >> 1;
            if(query(mid, ridx, 1, n, 1) < 2) lidx = mid;
            else ridx = mid;
          }
          ans = ridx;
          
          update(-2, ans, qidx - 1, 1, n, 1);
          ridxs.erase(ridxs.find(qidx));
          ridxs[ans] = 1;
          str[qidx] = '('; str[ans] = ')';
        }
      }
         
      printf("%d\n", ans);
    }
  }
  return 0;
}