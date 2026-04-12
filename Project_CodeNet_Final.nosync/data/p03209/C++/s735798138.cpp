#include <iostream>
using namespace std;

long pow2[60];

long R(long x, int l){
  if(l==1){
    if(x==1)return 0;
    if(x<=4)return x-1;
    if(x==5)return 3;
  }
  if(x==1)return 0;
  if(x<=pow2[l+1]-2)return R(x-1, l-1);
  if(x==pow2[l+1]-1)return pow2[l];
  if(x<=pow2[l+2]-4)return pow2[l]+R(x-pow2[l+1]+1, l-1);
  if(x==pow2[l+2]-3)return pow2[l+1]-1;
}

int main(){
  pow2[0]=1;
  for(int i=1; i<60; i++){
    cerr << pow2[i-1] << endl;
    pow2[i]=2*pow2[i-1];
  }
  long n, x;
  cin >> n >> x;
  cout << R(x, n);
  return 0;
}