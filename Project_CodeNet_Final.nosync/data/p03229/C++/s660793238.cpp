#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main(){
  int n,a,b,c,i,j,k;
  string s;
  cin >> n;
  long long x[n],y[n],ret=0,ret2=0;
  for(i=0;i<n;i++){
    cin >> x[i];
    y[i]=x[i];
  }
  sort(x,x+n);
  sort(y,y+n);
  reverse(y,y+n);
  for(i=0;i<n/2;i++){
    ret+=y[i]-x[i];
    //cout << y[i]-x[i] << endl;
    if(i!=0){
      ret+=y[i]-x[i-1];
      //cout << y[i]-x[i-1] << endl;
    }
  }
  if(n%2==0){
    ret+=y[0]-x[n/2-1];
    ret-=y[n/2-1]-x[n/2-1];
  }
  else {
    long long l;
    if(y[0]-x[n/2]>y[n/2]-x[n/2-1])ret+=y[0]-x[n/2];
    else ret+=y[n/2]-x[n/2-1];
    //ret+=abs(y[0]-x[n/2]);
  }
  //2pat
  for(i=0;i<n/2;i++){
    ret2+=y[i]-x[i];
    //cout << y[i]-x[i] << endl;
    if(i!=0){
      ret2+=y[i-1]-x[i];
      //cout << y[i]-x[i-1] << endl;
    }
  }
  if(n%2==0){
    ret2+=y[n/2-1]-x[0];
    ret2-=y[n/2-1]-x[n/2-1];
  }
  else {
    long long l;
    if(y[n/2]-x[0]>y[n/2-1]-x[n/2])ret2+=y[n/2]-x[0];
    else ret2+=y[n/2-1]-x[n/2];
    //ret+=abs(y[0]-x[n/2]);
  }
  cout << max(ret,ret2) << endl;
  return 0;
}
