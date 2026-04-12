#include<bits/stdc++.h>
using namespace std;
long calc(int n,long x,vector<long>p,vector<long>b){
  long ans = 0;
  if(n==0||x==0){
    return min(x,1l);
  }else{
    if(x<=1+p[n-1]+b[n-1])return calc(n-1,x-1,p,b);
    else return p[n-1]+1+calc(n-1,x-2-b[n-1]-p[n-1],p,b);
  }
}

int main(){
  int n;
  long x;
  cin >> n >> x;
  vector<long>p(51);
  vector<long>b(51);
  int i;
  p[0] = 1;
  b[0] = 0;
  for(i=1;i<=50;i++){
    p[i] = 2*p[i-1]+1;
    b[i] = 2*b[i-1]+2;
  }
  cout << calc(n,x,p,b) << endl;
}
