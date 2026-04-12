#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int K,A,B;
  cin>>K>>A>>B;
  if(A<=B){
    if(A>=K)
      puts("1");
    else
      puts("-1");
  }else
    cout<<max((K-B-1)/(A-B)*2,0LL)+1<<endl;
}