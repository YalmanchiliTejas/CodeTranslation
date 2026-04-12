#include <iostream>
#include <stdlib.h>
using namespace std;

int find(long k,long* A,int n);

int main(void){
  int n;
  cin>>n;
  long A[n];
  for(long i=0;i<n;i++){
    cin>>A[i];
  }

  int q;
  cin>>q;
  long k;
  for(int i=0;i<q;i++){
    cin>>k;
    cout<<find(k,A,n)<<endl;;
  }
  return 0;
}

int find(long k, long* A,int n){
  long low = 0;
  long high = n-1;
  long mid;
  while (high-low>10){
    mid = (high+low)/2;
    if(A[mid]>=k){
      high=mid;
    }
    else{
      low=mid;
    }
  }

  for(long i=low;i<=high;i++){
    if(A[i]>=k){
      return i;
    }
  }
  return n;
}

