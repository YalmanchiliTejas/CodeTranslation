#include<bits/stdc++.h>
using namespace std;
int main() {

while(true){
     int n;
     cin >> n;
     vector<int> A(n);
  
  if(n>0){
  for(int i=0;i<n;i++){
  
     cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  int sum=0;
  for(int i=1;i<n-1;i++){
  sum+=A.at(i);
  }
  cout << sum/(n-2) << endl;
  }
 if(n==0){
    break;
   }
}
}
