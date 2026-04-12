#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int h,w;
 cin>>h>>w;
 char a[10][10];
 int count=0;
 for(int i=0;i<h;i++){
   for(int j=0;j<w;j++){
     cin>>a[i][j];
     if(a[i][j]=='#'){count++;}
   }
 }
 if(count==h+w-1){cout<<"Possible"<<endl;}
 else{cout<<"Impossible"<<endl;}

return 0;
} 