#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
int64_t func(int64_t n,int64_t x){
  if(n==0){return 1;}
  int64_t b=pow((int64_t)2,n+1)-3;
  int64_t p=pow((int64_t)2,n)-1;//ひとつ前のものを利用
  if(x==1){return 0;}
  else if(x<=b+1){return func(n-1,x-1);}
  else if(x==b+2){return 1+p;}
  else if(x<2*b+2){return 1+p+func(n-1,x-2-b);}
  else {return 2*p+1;}
}
int main() {
  int64_t N,X;
  cin>>N>>X;
  cout<<func(N,X)<<endl;
  return 0;
}