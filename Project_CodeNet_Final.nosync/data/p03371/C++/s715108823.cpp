#include <bits/stdc++.h>
using namespace std;

int main(){
  int price_a,price_b,price_c,x,y;
  cin>>price_a>>price_b>>price_c>>x>>y;
  int price_ab=2*price_c;
  int ans=pow(10,9);
  int money;
  for(int i=0;i<=max(x,y);i++){
    money=price_ab*i+price_a*max(0,x-i)+price_b*max(0,y-i);
    ans=min(ans,money);
  }
  cout<<ans<<endl;

}