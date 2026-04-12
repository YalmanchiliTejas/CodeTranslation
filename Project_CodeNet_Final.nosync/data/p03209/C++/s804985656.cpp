#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<long>l(51),p(51);
long f(long n,long x){
  if(n==0){
    if(x<=0){
      return 0;
    }
    else{
      return 1;
    }
  }
  else if(x<=1+l.at(n-1)){
    return f(n-1,x-1);
  }
  else{
    return p.at(n-1)+1+f(n-1,x-2-l.at(n-1));
  }
}
int main() {
  long n,x;
  cin >>n>>x;
  l.at(0)=1;
  p.at(0)=1;
  rep2(i,1,51){
    l.at(i)=2*l.at(i-1)+3;
    p.at(i)=2*p.at(i-1)+1;
  }
  
  cout<<f(n,x)<<endl;
}