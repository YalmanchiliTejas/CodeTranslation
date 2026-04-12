#include<bits/stdc++.h>
using namespace std;
int64_t a(string &n,int k,int p,bool f){
  if(k==0)
    return 1;
  if(p+k>n.size())
    return 0;
  if(f){
    int64_t x=1;
    for(int i=0;i<k;i++)
      x*=(n.size()-p-i)*9;
    for(int i=k;i>0;i--)
      x/=i;
    return x;
  }
  int d=(int)(n.at(p)-'0');
  return (d>0?a(n,k-1,p+1,0)+a(n,k-1,p+1,1)*(d-1)+a(n,k,p+1,1):a(n,k,p+1,0));
}
int main(){
  string n;
  int k;
  cin>>n>>k;
  cout<<a(n,k,0,0)<<endl;
}