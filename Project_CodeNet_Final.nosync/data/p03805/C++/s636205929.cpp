#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int n, m;
int A[8][8]={};

int loop(int ind, vector<int> used){
  int flag=0;
  for(int i=1;i<n;i++){
    if (used[i]==0){
      flag=1;
      break;
    }
  }
  if (flag == 0){
    return 1;
  }
  int ans=0;
  for(int i=1;i<n;i++){
    if(used[i]==1) continue;
    if(A[ind][i]==1){
      used[i]=1;
      ans+=loop(i, used);
      used[i]=0;
    }
  }
  return ans;
}

int main(){
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    A[a-1][b-1]=A[b-1][a-1]=1;
  }
  int ans=0;
  vector<int> used(n, 0);
  used[0]=1;
  for(int i=1;i<n;i++){
    if (A[0][i] == 1){
      used[i]=1;
      ans += loop(i, used);
      used[i]=0;
    }
  }
  cout << ans << endl;
  return 0;
}