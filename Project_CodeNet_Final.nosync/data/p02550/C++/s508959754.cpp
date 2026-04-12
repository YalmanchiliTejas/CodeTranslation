#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t n,x,m,a,so,sy,ma;
  a=0;
  so=0;
  sy=0;
  ma=0;
  cin>>n>>x>>m;
  vector<int64_t> vec(m+1);
  vec.at(0)=x%m;
  for(int64_t i=0;i<m;i++){
  vec.at(i+1)=(vec.at(i)*vec.at(i))%m;
  }
  for(int64_t i=m;i>=0;i--){
  if(vec.at(m)==vec.at(i)){a=i;}
  }
  for(int64_t i=a;i<=(n-a-1)%(m-a)+a;i++){
  so=so+vec.at(i);}
  for(int64_t i=a;i<m;i++){
    sy=sy+vec.at(i);
  }
  for(int64_t i=0;i<=a-1;i++){
   ma=ma+vec.at(i);
  }
  cout<<ma+so+((n-a-1)/(m-a))*sy<<endl;
} 