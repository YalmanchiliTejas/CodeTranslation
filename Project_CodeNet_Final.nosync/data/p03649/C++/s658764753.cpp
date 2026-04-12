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
    if(a.at(i)>=n){
      k+=(a.at(i)-n)/(n+1)+1;
      a.at(i)=n+(a.at(i)-n)%(n+1)-(n+1);
    }
  }
  for(int i=0;i<n;i++)
    a.at(i)+=k;
  sort(a.begin(),a.end(),greater<int>());
  k+=max(a.at(n-1)-n,(int64_t)0)*n;
  for(int i=0;i<n;i++)
    a.at(i)-=max(a.at(n-1)-n,(int64_t)0);
  for(int i=0;a.at(i)>=n;i=(i+1)%n){
    for(int j=0;j<n;j++){
      if(i==j)
        a.at(j)-=n;
      else
        a.at(j)++;
    }
    k++;
  }
  cout<<k<<endl;
}