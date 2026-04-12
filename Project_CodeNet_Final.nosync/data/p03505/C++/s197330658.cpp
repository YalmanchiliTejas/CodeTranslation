#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  if(n<=a)
    cout<<1<<endl;
  else if(a<=b)
    cout<<-1<<endl;
  else{
    n-=a;
    a-=b;
    cout<<(n%a==0?n/a*2+1:(n/a+1)*2+1)<<endl;
  }
}