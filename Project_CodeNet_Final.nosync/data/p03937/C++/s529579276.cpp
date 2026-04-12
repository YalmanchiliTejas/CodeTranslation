#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int h,w;
  cin>>h>>w;
  string a[h];
  for(int i=0;i<h;i++) cin>>a[i];
  int x=h+w-1,c=0;
  for(int i=0;i<h;i++)
    c+=count(a[i].begin(),a[i].end(),'#');
  if(x==c) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
    
  return 0;
}
