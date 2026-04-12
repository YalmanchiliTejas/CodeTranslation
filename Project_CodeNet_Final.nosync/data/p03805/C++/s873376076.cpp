#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n,m,a[28],b[28];
  bool bo=false,co=false;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>a[i]>>b[i];
  }
  
  vector<int> c(n);
  for(int i=0;i<n;i++){
    c[i]=i+1;
  }
  
  int count=0;
  do{
    if(c[0]!=1)continue;
    co=false;
    for(int i=0;i<n-1;i++){
      bo=false;
      for(int j=0;j<m;j++){
        if((a[j]==c[i]&&b[j]==c[i+1])or(b[j]==c[i]&&a[j]==c[i+1]))bo=true;
       }
      if(bo!=1)break;
      if(bo==true&&i==n-2)co=true;
    }
    if(co){
      count++; 
    }     
  }while(next_permutation(c.begin(),c.end()));
  
  cout<<count<<endl;
  return 0;
}