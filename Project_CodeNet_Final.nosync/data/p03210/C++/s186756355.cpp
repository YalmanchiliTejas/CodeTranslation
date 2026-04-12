#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
 
using namespace std;
using std::cout;
using ll =long long;
bool is_int_lround(double x){
  return std::lround(x)==x;
}
int ketasuu(int x){
  int n=0;
  while(x>0){
    x /=10 ;
    n ++;
  }
  return n;
}
ll gcd11(ll x, ll y){
  long long a= max(x,y), b=min(x,y), c=a%b;
  while( c!=0){
    a =b;
    b =c;
    c = a%b;
  }
  return b;
}

int ab(int x, int y){
  if(x>=y){
    return x-y;
  }
  else if(y>x){
    return y-x;
  }
}
int main(){
  int X;
  cin>>X;
  if(X==3 || X==5 || X==7){
    cout<< "YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  
}
