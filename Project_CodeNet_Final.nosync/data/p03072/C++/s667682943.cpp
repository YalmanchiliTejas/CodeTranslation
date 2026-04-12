#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;cin>>n;
  int h[n];
  for(int i=0;i<n;i++)cin>>h[i];
  int ma=0;
  int ans=0;
  for(int i=0;i<n;i++){
    if(h[i]>=ma){
      ans++;
      ma=h[i];
    }
  }
  cout<<ans<<endl;
}