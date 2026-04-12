#include<iostream>
#include<algorithm>

using namespace std;

int main(){

   while(1){
      int n;
      cin>> n;
      if(n==0){
         break;
      }
      int s[n];
      for(int i=0; i<n; i++) cin>> s[i];

      int sum=accumulate(s, s+n, 0);
      int mi=*min_element(s, s+n);
      int ma=*max_element(s, s+n);

      cout<< (sum-mi-ma)/(n-2)<< endl;

   }

   return 0;
}