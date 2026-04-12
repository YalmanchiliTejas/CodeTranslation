#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
   long long int n;
   cin>>n;
   vector<long long int> h(n);
   for(long long int i=0; i<n; i++){
     cin>>h.at(i);
   }
   long long int nmax=h.at(0);
   long long int ans=1;
   for(long long int i=1; i<n; i++){
     if(nmax<=h.at(i)){
       ans++;
       nmax=h.at(i);
     }
   }
   cout<<ans<<endl;
}