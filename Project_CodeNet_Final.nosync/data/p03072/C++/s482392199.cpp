#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i) 
using namespace std;
using ll = long long;

int main(){
   int n;
   cin >> n;
   int h[22];
   rep(i,n) cin>>h[i];

   int count =1;
   int maxhight = h[0];
   for(int i=1; i<n;++i){
       if (h[i]>= maxhight){
           maxhight = h[i];
           count ++;
       }
   }
  cout << count << endl;
}