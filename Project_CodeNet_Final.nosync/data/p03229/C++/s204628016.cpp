#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
deque<int> dq,dq2;

signed main(){

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a,a+n);
  dq.push_back(a[0]);
  int right = n-1,left = 1;
  int cnt = 1;
  for(int i = 0; i < n; i++){
    if((i&1) == 0){
      dq.push_front(a[right--]);
      cnt++; if(cnt == n) break;
      dq.push_back(a[right--]);
      cnt++; if(cnt == n) break;
    }
    else {
      dq.push_front(a[left++]);
      cnt++; if(cnt == n) break;
      dq.push_back(a[left++]);
      cnt++; if(cnt == n) break;
    }
  }

  dq2.push_back(a[n-1]);
  right = n-2,left = 0;
  cnt = 1;
  for(int i = 0; i < n; i++){
    if((i&1) == 1){
      dq2.push_front(a[right--]);
      cnt++; if(cnt == n) break;
      dq2.push_back(a[right--]);
      cnt++; if(cnt == n) break;
    }
    else {
      dq2.push_front(a[left++]);
      cnt++; if(cnt == n) break;
      dq2.push_back(a[left++]);
      cnt++; if(cnt == n) break;
    }
  }
  int ans = 0,ans2 = 0;
  for(int i = 0; i < n-1; i++){
    //cout << dq[i] << " ";
    ans += abs(dq[i+1]-dq[i]);
    ans2 += abs(dq2[i+1]-dq2[i]);
  }
  cout << max(ans,ans2) << endl;

  return 0;
}
