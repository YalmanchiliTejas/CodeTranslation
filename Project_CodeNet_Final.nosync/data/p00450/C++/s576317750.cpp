#include<iostream>
using namespace std;
int main(){
  int n;  
  while(1){
    cin>>n;
    if(n==0)break;
    int a,c[100001];
    for(int i=0;i<n;i++){
      cin>>a;
      c[i]=a;
      int j=i-1;
      if(i%2==1)while(c[j]!=a&&j>=0)c[j]=a,j--;
      }
    a=0;
    for(int i=0;i<n;i++)if(c[i]==0)a++;
    cout<<a<<endl;  
  }
  return 0;
} 