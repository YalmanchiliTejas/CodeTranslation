#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> data(n);
  for(int i=0;i<n;i++)cin>>data[i];
  int ans=0;
  for(int i=0;i<n;i++){
    bool view=true;
    for(int j=0;j<i;j++){
      if(data[j]>data[i])view=false;
    }
    if(view)ans++;
  }
  cout<<ans<<endl;
}