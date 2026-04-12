#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  int N; cin >> N; vector<long long > A(N); 
  for(int i = 0; i < N; i++){ cin >> A[i];}
                                 
  sort(A.begin(),A.end());
  
  ll ans = 0;
  
  if( N % 2 ){
    // when N is a odd number 
   for(int p = 0; p <= 1; p++){
     if( p ){ reverse(A.begin(),A.end());} ll res = 0;
             
    vector<long long> B(N);
             
    B[ ( N -1 )/ 2 ] = A[N-1];
    for(int i = 1; i <= ( N - 1) / 2 ; i++){
      if( i % 2){ B[ ( N - 1) / 2  + i] = A[ i-1];}
      else{ B[ ( N  - 1) / 2 + i ] = A[ N - i];}}
    
    for(int j = 1; j <= ( N - 1) / 2; j++){
      if(j % 2){ B[( N - 1) / 2 - j] = A[j];}
      else{ B[ (N - 1)/ 2 - j] = A[N - j - 1];}} 
    
    for(int i = 0; i < N - 1; i++){ res += abs( B[i+1] - B[i]);}
    ans = max( ans, res);}
   }// if closed
  
  else{
     // when N is a even number 
   for(int p = 0; p <= 1; p++){
     if( p ){ reverse(A.begin(),A.end());} ll res = 0;
             
    vector<long long> B(N);
             
    B[ (N / 2) - 1 ] = A[N-1];
    for(int i = 0; i <= N / 2 - 1 ; i++){
      if( i % 2){ B[ N / 2  + i] = A[ N - i- 1];}
      else{ B[ N / 2 + i ] = A[i];}}
    
    for(int j = 2; j <=  N / 2; j++){
      if(j % 2){ B[ N / 2 - j] = A[ N - j];}
      else{ B[ N/ 2 - j] = A[j - 1];}} 
    
    for(int i = 0; i < N - 1; i++){ res += abs( B[i+1] - B[i]);}
    ans = max( ans, res);}
   }// else closed
  
    
    
    
    
    
              
      cout << ans << endl; return 0;}
              
       
        