#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t n,x,y;
  cin>>n;
  x=0;
  y=0;
  vector<int64_t>a(n);
  for(int64_t i=0;i<n;i++){
    cin>>a.at(i);
    x=(x+a.at(i))%1000000007;
    y=(y+a.at(i)*a.at(i))%1000000007;
  }
  if(((x*x-y)%1000000007)%2==0){
    cout<<((x*x-y)%1000000007)/2<<endl;
    }
  else{
    cout<<((x*x-y)%1000000007+1000000007)/2<<endl;
  
  }
}