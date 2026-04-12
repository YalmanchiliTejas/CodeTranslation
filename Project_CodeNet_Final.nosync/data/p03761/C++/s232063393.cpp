#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  string s[n],ans="",tmp;
  int a[n]={};
  for(int i=0;i<n;i++){
    cin >> s[i];
    sort(s[i].begin(),s[i].end());
    if(i==0){
      tmp=s[i];
    }
    if(tmp.size()>s[i].size()){
      tmp=s[i];
    }
  }
  for(int i=0;i<tmp.size();i++){
    int cnt=0;
    for(int j=0;j<n;j++){
      int x=0;
      for(int k=a[j];k<s[j].size();k++){
        if(tmp[i]==s[j][k]&&x==0){
          cnt++;
          x++;
          a[j]=k+1;
        }
      }
    }
    if(cnt==n){
      ans+=tmp[i];
    }
  }
  cout << ans << endl;  
  return 0;
}
