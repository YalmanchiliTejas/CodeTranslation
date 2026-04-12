#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  
  int n,m,a[20000],b,max;
  
  
  while(1){
    
    cin >>n>>m;
  
  if( n == 0 && m == 0)break;
  
  for(int i=0 ; i < n  ; i++){
    cin >>a[i];
  }
  for(int i=n; i < n+m ; i++){
    cin >>a[i];  
  }
  
  sort(a,a+n+m);

  max=a[0];
  
  for(int i=0 ; i < n+m-1 ; i++){
      if(a[i+1]-a[i] > max){
	max=a[i+1]-a[i];
      }
    }
    
    cout <<max<<endl;
    
  }
  
  return 0;
}