#include<iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int a[200000];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long long ans=0,s=0;
  for(int i=0;i<n;i++){
    ans=((s*a[i])+ans)%(1000000000+7);
    s=(s+a[i])%(1000000000+7);
  }
  cout<<ans<<endl;
}

	   
