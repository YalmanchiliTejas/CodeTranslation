#include<bits/stdc++.h>
using namespace std;
int main(){
  int p;
  int s[1000];
  int sum;
  while(1){
    sum=0;
    cin>>p;
    if(p==0) break;
    for(int i=0;i<p;i++){
      cin>>s[i];
      sum+=s[i];
    }
    sort(s,s+p);
    for(int j=0;j<p;j++){
      /* cout<<s[j]<<endl;*/
    }
    cout<<(sum-s[0]-s[p-1])/(p-2)<<endl;
  }
  return 0;
}
    
