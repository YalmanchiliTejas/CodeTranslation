#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<utility>


using namespace std;
typedef long long ll;
int main(){
ll h,w;
  cin>>h>>w;
char a[h][w];
  for(ll i=0;i<h;i++){
  for(ll j=0;j<w;j++){
  cin>>a[i][j];
  
  }
 
  }
  ll memoh=h;
  ll memow=w;
  ll nowh=0;
  ll noww=0;
char a2[h][w];
  for(ll i=0;i<h;i++){
    int flag=0;
  for(ll j=0;j<w;j++){
  if(a[i][j]=='#'){
  flag=1;
    break;
  }
  }
    if(flag==1){
    for(ll j=0;j<w;j++){
      a2[nowh][j]=a[i][j];
     
    }
       nowh++;
    }
  }
  char a3[h][w];
    for(ll i=0;i<w;i++){
    int flag=0;
  for(ll j=0;j<nowh;j++){
  if(a2[j][i]=='#'){
  flag=1;
    break;
  }
  }
    if(flag==1){
    for(ll j=0;j<nowh;j++){
      a3[j][noww]=a2[j][i];
     
    }
       noww++;
    }
  }
  
  
  
    for(ll i=0;i<nowh;i++){
  for(ll j=0;j<noww;j++){
  cout<<a3[i][j];
  }
      cout<<endl;
  }
return 0;
}
