#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
   long long int N,count=1;
   cin >>N; long long int M[N];
   for(long long int i=0;i<N;i++){
   cin >> M[i];
   }
   long long int a=M[0];
   for(long long int i=1;i<N;i++){
       a=max(a,M[i]);
       if(a<=M[i])count++;
   }
   cout <<count;

}
