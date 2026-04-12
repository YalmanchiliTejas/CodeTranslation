#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

li solve(li x,const vector<li>& bgr,const vector<li>& pty,int n){
  if(x<=n) return 0;
  else if(x==bgr[n]){
    return pty[n];
  }else if(x>=bgr[n-1]+2){
    return pty[n-1]+solve(x-bgr[n-1]-2,bgr,pty,n-1)+1;
  }else if(x==bgr[n-1]+1){
    return pty[n-1];
  }else{
    return solve(x-1,bgr,pty,n-1);
  }
}

int main(){
  int n; li x; cin >>n >>x;
  vector<li> bgr(n+1,0),pty(n+1,0);
  bgr[0]=1;pty[0]=1;
  rep(i,n){
    bgr[i+1]=bgr[i]*2+3;
    pty[i+1]=pty[i]*2+1;
  }
  print(solve(x,bgr,pty,n));
}
