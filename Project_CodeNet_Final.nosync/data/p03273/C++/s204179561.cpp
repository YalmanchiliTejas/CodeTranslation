#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
char w[a][b];
vector<int>h(a),t(b);
  for(int i=0;i<a;i++){
  h[i]=0;
  }
    for(int i=0;i<b;i++){
  t[i]=0;
    }
for(int i=0;i<a;i++){
  for(int j=0;j<b;j++){
  cin>>w[i][j];
    if(w[i][j]=='#'){
      h[i]=1;
        t[j]=1;
    }
  }
}

for(int i=0;i<a;i++){
  for(int j=0;j<b;j++){
  if(h[i]==1&&t[j]==1){
      cout<<w[i][j];
    }
  }
      if(h[i]!=0){
        cout<<endl;
      }
}
}