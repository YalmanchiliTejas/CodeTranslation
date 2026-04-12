#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = numeric_limits<ll>::max()/3;
const ll mod = 1e9 + 7;

int now[100010];

int main(void){
  int n;
  fill(now,now+100010,-1);
  cin >> n;
  int res = 0;
  for(int i = 0;i < n;++i){
    int a;
    cin >> a;
    int ok = res;
    int ng = -1;
    while(abs(ok - ng) > 1){
      int mid = (ok + ng)/2;
      if(now[mid] < a){
        ok = mid;
      }else{
        ng = mid;
      }
    }
    if(ok == res){
      ++res;
    }
    now[ok] = a;
  }
  cout << res << endl;
  return 0;
}
