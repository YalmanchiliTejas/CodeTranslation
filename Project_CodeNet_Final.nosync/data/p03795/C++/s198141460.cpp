#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
int in() {int x;scanf("%lld",&x);return x;}
int main(){
  int n=in();
  cout<<n*800-(n/15)*200<<endl;
}