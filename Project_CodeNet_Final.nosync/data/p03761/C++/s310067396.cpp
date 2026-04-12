#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > v(n,vector<int>(26,0));
  for(int i=0;i<n;i++){
    string S;
    cin >> S;
    for(int j=0;j<S.size();j++){
      v.at(i).at(S.at(j)-'a')++;
    }
  }
  vector<int> ans(26);
  for(int i=0;i<26;i++){
    ans.at(i)=v.at(0).at(i);
    for(int j=1;j<n;j++){
      ans.at(i)=min(ans.at(i),v.at(j).at(i));
    }
    cout << string(ans.at(i),i+'a');
  }
  cout << endl;
  return 0;
}
