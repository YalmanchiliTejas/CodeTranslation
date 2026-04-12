#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


int main() {
   int n;
 
   cin >> n;
  
   int a[n];
  
  for(int i = 0;i<n;i++){
     
    cin >> a[i];

   }

  
   int sum = 1;
   int max = a[0];
  
   for(int i = 1;i<n;i++){
     
     if(max<a[i]){
       
       max=a[i];
       
     }
     
     if(max<=a[i]&&a[i-1]<=a[i]){
       
      
         
          sum=sum+1;
         
       
     }
  

   }
   cout << sum << endl;
   
  return 0;
}