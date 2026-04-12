#include<bits/stdc++.h>
using namespace std;
int main(){
  map<long long,int>m;
  long long n,ans=0,a[200000],x;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    a[i]=i?a[i-1]+x:x;
    if(!m[a[i]])m[a[i]]=i+1;
  }
  for(int i=0;i<n;i++){
    if(m[a[i]])if(i-m[a[i]]+1>ans)ans=i-m[a[i]]+1;
    if(!a[i])ans=i+1;
  }
  cout<<ans<<endl;
}