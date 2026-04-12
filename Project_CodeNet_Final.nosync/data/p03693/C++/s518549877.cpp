#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define mk make_pair
#define se second
#define fi first
using namespace std;
int main(){
  int a[3];
  cin>>a[0]>>a[1]>>a[2];
  int s=a[0]*100+a[1]*10+a[2];
  if(s%4==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}