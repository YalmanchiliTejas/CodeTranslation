#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

  cin.tie(0);     // cout と cin の同期を切る
  ios::sync_with_stdio(false);  /* cの stdioストリーム (printfとか)と*/

  int n;

  cin>>n;
  
  int a[200001];


  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  if(n%2==0){
    
    for(int i=n-1;i>0;i-=2){
      cout<<a[i]<<" ";
    }
    
    for(int i=0;i<n;i+=2){
      
      if(i>=n-2){
	cout<<a[i]<<endl;
      }else{
	cout<<a[i]<<" ";
      }
    }
  }
  else{

    for(int i=n-1;i>=0;i-=2){

      if(n==1){
	cout<<a[i]<<endl;
      }else{
	cout<<a[i]<<" ";
      }      
      
    }
    
    for(int i=1;i<n;i+=2){
      
      if(i>=n-2){
	cout<<a[i]<<endl;
      }else{
	cout<<a[i]<<" ";
      }
    }
  }
  return 0;

}
