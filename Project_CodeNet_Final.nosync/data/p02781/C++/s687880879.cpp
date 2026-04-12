#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll c(int a, int b){
  ll ans=1;
  ll m=1;
  if(a==0) return 1;
  for(int i=0; i<b; i++){
    ans *=a;
    a--;
    m *=(i+1);
  }
  ans /=m;
  return ans;
}
int main(){
  string s;
  int k;
  cin>>s>>k;
  int n=s.size();
  ll ans=0;
  int a=s.at(0) - '0';
  int nin=1;
  for(int i=0 ; i<k ; i++){
    nin *= 9;
  }
  if(n<k){
    cout<<0<<endl;
    return 0;
  }
  else{
    int count=0;
    int keta=0;//ketaは左からk桁のときk-1
    while(count<k&&keta<n){
      int tmp=s.at(keta)-'0';
      if(tmp==0){
        keta++;
        continue;
      }
      else if(tmp==1){
        ans +=nin*c(n-keta-1,k-count);
        count++;
        nin/=9;
        keta++;
      }
      else{
        ans += (tmp-1)*(nin/9)*c(n-keta-1,k-count-1)//1~b-1
          +nin*c(n-keta-1,k-count)*min(1,n-keta-1);//0
        count++;
        nin/=9;
        keta++;
      }
      
    }
    if(count==k) ans++;
    cout<<ans<<endl;
  }
}