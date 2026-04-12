#include<bits/stdc++.h>
using namespace std;

int dfs(int num, int n, bitset<8> seen, vector<vector<bool>> list) {
  seen.set(num,0);
  int ans=0;
  if(seen.count()==0) {
    ans=1;
  }
  else {
    for(int i=1;i<n;i++) {
      if(list.at(num).at(i)&&seen.test(i)) {
        ans+=dfs(i,n,seen,list);
      }
    }
  }
  return ans;
}
  

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<bool>> list(n,vector<bool>(n,false));
  for(int i=0;i<m;i++) {
    int temp1,temp2;
    cin >> temp1 >> temp2;
    temp1--;
    temp2--;
    list.at(temp1).at(temp2)=true;
    list.at(temp2).at(temp1)=true;
  }
  bitset<8> seen((1<<n)-1);
  cout << dfs(0, n, seen, list) << endl;
}