#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using int64=int64_t;
const int inf=100000000;

int in(){
  int a;
  cin >> a;
  return a;
}//int型関数の受け取り

void forin(int* x,int y){
  for (int i=0;i<y;i++){
    cin >> x[i];
  }
}//(x,y) int型配列x[y]の受け取り

int intpow(int x,int y){
  double a=x,b=y;
  return pow(a,b);
}//(x,y) xをy乗

int intfabs(int x){
  double a=x;
  return fabs(a);
}//(x) xの絶対値

int fact(int x){
  if (x == 1) return 1;
  return x*fact(x-1);
}//(x) x!

int fib(int x){
  if (x <= 2) return x;
  int a[x];
  a[0]=1;
  a[1]=2;
  for (int i=2;i<x;i++){
    a[i]=a[i-1]+a[i-2];
  }
  return a[x-1];
}//(x) フィボナッチ数列のx番目

int div1(ll x){
  return x%1000000007;
}

main(){
    int x=in(),y=in(),z=in();
    x-=z;
    cout << x/(y+z) << endl;
}