#include <bits/stdc++.h>
using namespace std;

int req(int N,int now,vector<bool> passed,vector<int> num,vector<vector<bool>> mp) {
  if (now == N) {
    for (int i=0; i<N-1; i++) {
      if (!mp[num[i]][num[i+1]]) {
        break;
      }
      if (i==N-2) {
        return 1;
      }
    }
    return 0;
  }
  int ans = 0;
  for (int i=1; i<N; i++) {
    if (passed[i]) {
      continue;
    }
    num[now] = i;
    passed[i] = true;
    ans += req(N,now+1,passed,num,mp);
    passed[i] = false;
  }
  return ans;
}

int main() {
  int N,M,A,B;
  cin >> N >> M;
  vector<vector<bool>> mp(N,vector<bool> (N,false));
  
  for (int i=0; i<M; i++) {
    cin >> A >> B;
    mp[A-1][B-1] = true;
    mp[B-1][A-1] = true;
  }
  
  vector<bool> passed(N,false);
  passed[0] = true;
  vector<int> num(N,0);
  
  cout << req(N,1,passed,num,mp) << endl;
  
  return 0;
}