#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  li n,x,m; cin >>n >>x >>m;
  vector<li> v(m,0);
  li a=x,t,c=1;
  while(1){
    (a*=a)%=m;
    if(v[a]){
      t=c-v[a];
      break;
    }else{
      v[a]=c++;
    }
  }
  li tail=c-t,q=(n-tail)/t,r=(n-tail)%t;
  li ans=0;
  a=x;
  rep(i,tail+r){
    ans+=a;
    a=a*a%m;
  }
  li period=0;
  rep(i,t){
    period+=a;
    a=a*a%m;
  }
  ans+=period*q;
  print(ans);
}
