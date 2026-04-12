#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
  int N;
  cin>>N;
  vector<int> com(26,100);
  for(int i=0;i<N;i++){
    string S;
    cin>>S;
    vector<int> cnt(26);
    for(int j=0;j<S.size();j++)
      cnt[S[j]-'a']++;
    for(int j=0;j<26;j++)
      com[j] = min(com[j],cnt[j]);
  }
  string ans ="";
  for(int i=0;i<26;i++)
    for(int j=0;j<com[i];j++)
      ans += 'a' + i;
  cout<<ans<<endl;
  return 0;
}
