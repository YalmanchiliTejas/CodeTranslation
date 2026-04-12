#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  vector<int>sum(26,INT_MAX);
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<int> a(26,0);
    for(int j=0;j<s.size();j++){
      for(char c='a';c<='z';c++){
        if(s[j]==c){
          int b=c-'a';
          a[b]++;
          break;
        }
      }
    }
    for(int j=0;j<26;j++){
      sum[j]=min(sum[j],a[j]);
    }
  }
  for(int i=0;i<26;i++){
    if(sum[i]!=0){
      for(int j=0;j<sum[i];j++){
        char c=i+'a';
        cout<<(char) c;
      }
    }
  }
  cout<<endl;
  return 0;
}