#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  char a[12];
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  cin>>k;
  for(int i=1;i<=n;i++){
  	if(a[i]!=a[k]){
      cout<<'*';
    }
    else{
      cout<<a[i];
    }
  }
}
  