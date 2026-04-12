#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int64_t> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  int64_t k=0;
  for(int i=0;i<n;i++){
    k+=a.at(i)/(n+1);
    a.at(i)=a.at(i)%(n+1);
  }
  vector<int> b(n+1,0);
  for(int i=0;i<n;i++)
    b.at(a.at(i))++;
  for(int i=0,p=n;i<n;i++){
    while(b.at(p)==0)
      p--;
    a.at(i)=p+k;
    b.at(p)--;
  }
  int64_t m=a.at(0)*n;
  for(int i=0;i<n;i++)
    m=min(m,i+max(a.at(i)+i-n+1,(int64_t)0)*n);
  cout<<k+m<<endl;
}