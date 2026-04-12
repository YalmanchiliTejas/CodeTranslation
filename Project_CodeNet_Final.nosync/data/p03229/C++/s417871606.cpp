#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main(){
  int N;
  cin >>N;
  int A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }

  sort(A,A+N);
  long long int ans=0;
  if(N%2){
    if(A[N/2]*2-A[N/2-1]-A[N/2+1]>=0){
        for(int i=N-1;i>=N/2+2;i--){
          ans+=A[i]*2;
        }
        ans+=A[N/2]+A[N/2+1];
        for(int i=N/2-1;i>=0;i--){
          ans-=A[i]*2;
        }
      }
     else{
       for(int i=N-1;i>N/2;i--){ 
        ans+=A[i]*2;
      }
      ans-=A[N/2]+A[N/2-1];
      for(int i=N/2-2;i>=0;i--){
        ans-=A[i]*2;
      }
    }
  }
  else{
    for(int i=N-1;i>=N/2+1;i--){
    ans+=A[i]*2;
    }
    for(int i=0;i<=N/2-2;i++){
      ans-=A[i]*2;
    }
    ans+=A[N/2]-A[N/2-1];
  }

  
  
  
  
  
  
  
  
  
  
  
  cout<<ans;
  return 0;
}








