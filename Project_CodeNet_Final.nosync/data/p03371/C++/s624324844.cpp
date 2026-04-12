#include<iostream>
using namespace std;
int num(int n,int i){
  if(n-i>=0) return n-i;
  else return 0;
}
int main(){
  int ap,bp,abp,abd,x,y,i,min=2000000000,la,su,tx,ty;
  cin >> ap >> bp >> abp >> x >> y;
  abd=2*abp;
  la = (x>y) ? x : y;
  for(i=0;i<=la;i++){
    su = abd*i + num(x,i)*ap + num(y,i)*bp;
    if(min > su){
      min = su;
    }
  }
  cout << min;
}
