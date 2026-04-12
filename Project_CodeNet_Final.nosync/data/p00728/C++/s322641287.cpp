#include<iostream>
#include<cstdio>

using namespace std;

int main(){

  int n;
  int max,min;
  int a;
  int sum;
  while(true){
    cin >>n;
    if(n==0)break;
    sum = 0;
    max = 0;
    min = 1001;
    for(int i=0;i<n;i++){
      cin >>a;

      if(a>max)max = a;
      if(a<min)min = a;
      sum+=a;
    }
    sum-=max+min;
    sum/=(n-2);
    cout <<sum<<endl;
  }


  return 0;
}