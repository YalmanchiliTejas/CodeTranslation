#include <bits/stdc++.h>
using namespace std;
#include<cstdio>
#define r(i,n) for(int i=0;i<n;i++)


int main(void){
  char a,b,c;
  cin>>a>>b>>c;
  int a_=(a-'0')*100;
  int b_=(b-'0')*10;
  int c_=(c-'0');
  //cout<<a_<<" "<<b_<<" "<<c_<<endl;
  int x=a_+b_+c_;

  if(x%4==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
