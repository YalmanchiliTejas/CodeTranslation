#include<iostream>
#include<algorithm>
using namespace std;
int i[300000];
int an[300000];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c=0,d,e,f,g;
  cin >>a;
  for(int n=0;n<a;n++){
    cin >>i[n];
  }
  for(int n=a-1;n>=0;n=n-2){
    an[c]=i[n];
    c++;
  }
  if(a%2==0){
    for(int n=0;n<a;n=n+2){
      an[c]=i[n];
      c++;
    }
  }
  else{
    for(int n=1;n<a;n=n+2){
      an[c]=i[n];
      c++;
    }
  }
  for(int n=0;n<a;n++){
    if(n!=0) cout <<' ';
    cout <<an[n];
  }
  cout <<'\n';
  return(0);
}
