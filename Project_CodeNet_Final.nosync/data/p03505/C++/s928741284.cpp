#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll k,a,b;cin>>k>>a>>b;
  if(k<=a){
    cout<<1<<endl;
    return 0;
  }
  if(a<=b){
    cout<<-1<<endl;
    return 0;
  }
  ll ans=(k-a-1)/(a-b);
  ll now=ans*(a-b);
  ans*=2;
  for(;;){
    if(now+a>=k){
      cout<<ans+1<<endl;
      return 0;
    }
    ans+=2;
    now+=a-b;
  }
}
