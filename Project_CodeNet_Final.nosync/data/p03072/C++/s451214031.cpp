#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,ans=0;
  cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a.at(i);
  int max=a.at(0);
  rep(i,n){
   if(a.at(i)>=max){
   ans++;
     max=a.at(i);
   }
  }
  cout<<ans<<endl;
}