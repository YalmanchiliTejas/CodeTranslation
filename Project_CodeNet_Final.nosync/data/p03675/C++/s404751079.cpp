#include<iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  if(n%2==1){
    for(int i=0;i<(n+1)/2;i++){
      cout << a[n-1-(i*2)] << " ";
    }
    for(int i=0;i<(n-1)/2;i++){
      cout << a[i*2+1] << " ";
    }
  }else if(n%2==0){
    for(int i=0;i<n/2;i++){
      cout << a[n-1-(i*2)] << " ";
    }
    for(int i=0;i<n/2;i++){
      cout << a[i*2] << " ";
    }
  }
  cout << endl;
  return 0;
}
  
