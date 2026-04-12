#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdexcept>
#include<stdio.h>
using namespace std;

int main(){
  int n; cin >> n;
  int h[n]; int ans=0;
  for(int q=0;q<n;q++) {
    cin >> h[q];
  }
 if(n==1) cout << '1' <<endl;
  
 else{
  if(h[0]<=h[1]) ans++;
  
   for(int i=2;i<n;i++){
     int res=0;
     for(int j=0;j<i;j++){
       if(h[j] <= h[i]) res++;
     }
     if(res == i) ans++;
   }
   cout << ans+1 <<endl;
  }
   return 0;
}