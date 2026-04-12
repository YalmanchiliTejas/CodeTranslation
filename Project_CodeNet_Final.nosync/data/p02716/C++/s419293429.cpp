#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  if(n%2==0){
    int64_t s=0;
    vector<int64_t> m(n+1,0);
    for(int i=2;i<=n;i+=2){
      m[i]=m[i-2]+a.at(i-1);
      s+=a.at(i-2);
      m[i]=max(m[i],s);
    }
    cout<<m[n]<<endl;
  }
  else{
    int64_t sl=0;
    vector<int64_t> ml(n,0);
    for(int i=2;i<n;i+=2){
      ml[i]=ml[i-2]+a.at(i-1);
      sl+=a.at(i-2);
      ml[i]=max(ml[i],sl);
    }
    int64_t sr=0;
    vector<int64_t> mr(n,0);
    for(int i=n-3;i>=0;i-=2){
      mr[i]=mr[i+2]+a.at(i+1);
      sr+=a.at(i+2);
      mr[i]=max(mr[i],sr);
    }
    int64_t m;
    for(int i=0;i<n;i+=2)
      m=(i==0?ml[i]+mr[i]:max(m,ml[i]+mr[i]));
    cout<<m<<endl;
  }
}