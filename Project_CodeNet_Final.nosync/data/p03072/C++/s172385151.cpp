#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>

using namespace std;
int main(void){
 int a,N,check;
 int ans=1;
 vector<int> H;
 
 cin>>N;
 for(int i=0; i<N;i++){
  cin>>a; 
  H.push_back(a);
 }
 check=0;

 for(int i=1;i<N;i++){
  for(int j=i-1; j>=0; j--){
   if(H[j]<=H[i]);
   else check=1;
  }
  if(check==0)ans++;
  check=0;
 }
 
 cout<<ans<<endl;
 return 0;
}