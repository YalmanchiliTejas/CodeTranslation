#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n;
  cin>>n;
  string s[n];
  for(int i=0;i<n;i++) cin>>s[i];
  int a[26];
  fill(a,a+26,100000);
  for(int i=0;i<26;i++){
    for(int j=0;j<n;j++){
      int temp=0;
      for(int k=0;k<s[j].size();k++){
        if(s[j][k]==char(i+'a')) temp++;
      }
      a[i]=min(a[i],temp);
    }
  }
  string ans="";
  for(int i=0;i<26;i++){
    if(a[i]==0 or a[i]==100000) continue;
    for(int j=0;j<a[i];j++) ans+=char(i+'a');
  }
  cout<<ans<<endl;
}
