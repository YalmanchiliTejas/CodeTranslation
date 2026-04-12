#include "bits/stdc++.h"

using namespace std;

int main() {
   int n;
   cin >> n;
   int mx;
   int i=1;
   int co=0;
   int h;
   while(i<=n){
       cin >> h;
       if(i==1){
           mx=h;
           co=co+1;
       }
    else if(mx<=h){
           mx=h;
           co=co+1;
       }
       i=i+1;
   }
   cout << co << endl;
   return 0;
}