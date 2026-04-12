#include<bits/stdc++.h>
using namespace std;

int main(){
 int a;
  char f;
  cin>>a;
vector<string>c(a);
vector<int>d(26);
  vector<int>e(26);
  for(int i=0;i<26;i++){
    d[i]=1000;
  }
  for(int i=0;i<a;i++){
    cin>>c[i];
  }
  for(int i=0;i<a;i++){
    for(int j=0;j<c[i].size();j++){
      for(int u=0;u<26;u++){
        if(c[i][j]-'a'==u){
          e[u]++;
        }
      } 
    }
     for(int j=0;j<26;j++){
       d[j]=min(d[j],e[j]);
       e[j]=0;
     }
  }
  for(int i=0;i<26;i++){
    f='a'+i;
    for(int j=0;j<100000;j++){
    if(d[i]!=0){
       cout<<f;
    d[i]--;
    }
      else{
        break;
      }
    }
  }
cout<<endl;
      
}