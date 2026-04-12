#include <bits/stdc++.h>
using namespace std;

int main() {
 int n ;
 cin >>n;
  vector<int> h(n);
 int ans =n;
 for(int i=0;i<n;i++){
   cin >>h.at(i);
 }
 int minmum =h.at(0);
 for(int i=0;i<n;i++){
    if (h.at(i)<minmum){
      ans--;
     // cout <<i<<endl;
    }
   minmum=max(h.at(i),minmum);
           }
  cout <<ans ;
}