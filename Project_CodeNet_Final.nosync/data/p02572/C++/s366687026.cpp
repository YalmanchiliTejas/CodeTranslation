#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  long long y=0,z=0;
  for(int j=0;j<n;j++){
    y+=x[j];
    z+=x[j]*x[j];
  }
  long long m=round(pow(10,9))+7,t=0;
  for(int k=0;k<n;k++){
    t+=((y-x[k])%m)*x[k]%m;
    t=t%m;
  }
  for(int l=0;l<m/10;l++){
    t=t*1024%m;
  }
  
  cout<<t*32%m<<endl;
}
