#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  string s;
  int b[200]={};

  cin>>s;
  for(int i=0;i<s.size();i++){
    b[(int)s[i]]+=1;
  }

  for(int i=1;i<n;i++){
    int a[200]={};
    cin>>s;

    for(int j=0;j<s.size();j++){
      a[(int)s[j]]+=1;
    }

    for(int k=0;k<200;k++){
      b[k]=min(b[k],a[k]);
    }
  }

  for(int i=0;i<200;i++){
    while(b[i]>0){
      cout<<(char)i;
      b[i]-=1;
    }
  }
  
  
  return 0;
}
