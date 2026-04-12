#include<iostream>
using namespace std;

int main(){
  int n;
  while(1){
    cin >> n;
    if(n == 0)
      break;
    int x[n];
    for(int i=0;i<n;i++){
      cin >> x[i];
    }

    //sort
    int t;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        if(x[i]<x[j]){
          t = x[i];
          x[i] = x[j];
          x[j] = t;
        }
      }
    }

    //calc
    int sum=0;
    for(int i=1;i<n-1;i++){
      sum+=x[i];
    }
    cout << sum/(n-2) << "\n";
  }
  return 0;
}