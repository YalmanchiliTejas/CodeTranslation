#include<bits/stdc++.h>

using namespace std;


long long int DP[3001][3001][2];

long long int maximizexminusy(long long int *arr,int n,int i,int j,int turn){

    if(i>j)
    return 0; 

     if(DP[i][j][turn]!=-1)
  return DP[i][j][turn];


   else{


    if(turn==0)
     return DP[i][j][turn]=max(arr[i]+maximizexminusy(arr,n,i+1,j,1),arr[j]+maximizexminusy(arr,n,i,j-1,1));
    
    else
     return DP[i][j][turn]=min(maximizexminusy(arr,n,i+1,j,0),maximizexminusy(arr,n,i,j-1,0));


   }

  //return DP[i][j][turn];



}


int main(){



  int n;

  cin>>n;

  long long int arr[n];
  long long int sum=0;

  for(int i=0;i<n;i++){
  	cin>>arr[i];
  	sum+=arr[i];
  }

 memset(DP,-1,sizeof DP);
  
  long long int x=maximizexminusy(arr,n,0,n-1,0);
  //cout<<x;
  
  long long int y=sum-x;

   cout<<(x-y)<<endl;
   

	return 0;
}