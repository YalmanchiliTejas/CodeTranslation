#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int i,n,ima=0,k;
  int a[3],keta[3];
  a[0]=0;
  a[1]=0;
  a[2]=0;
  keta[0]=1;
  keta[1]=1;
  keta[2]=1;
  long long int kotae=0;
  cin>>k;
  n=s.length();
  if(n<k){
    cout<<0;
    return 0;
  }
  for(i=0;i<n;i++){
    if(s[i]!='0'){
      a[ima]=s[i]-'0';
      keta[ima]=n-i;
      ima++;
    }
    if(ima==3){
      break;
    }
  }
  if(k==3){
    kotae+=(((keta[0]-1)*(keta[0]-2)*(keta[0]-3))/6)*729;
    kotae+=(((keta[0]-1)*(keta[0]-2))/2)*81*(a[0]-1);
    kotae+=(((keta[1]-1)*(keta[1]-2))/2)*81;
    kotae+=(keta[1]-1)*9*(a[1]-1);
    kotae+=(keta[2]-1)*9;
    kotae+=a[2];
  }
  if(k==2){
    kotae+=(((keta[0]-1)*(keta[0]-2))/2)*81;
    kotae+=(keta[0]-1)*9*(a[0]-1);
    kotae+=(keta[1]-1)*9;
    kotae+=a[1];
  }
  if(k==1){
    kotae+=(keta[0]-1)*9;
    kotae+=a[0];
  }
  cout<<kotae;
}