#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 int H,W;
 cin>>H>>W;
 char a[110][110];
 for(int i=0;i<H;i++){
     for(int j=0;j<W;j++){
         cin>>a[i][j];
     }
 }
 vector<bool>h(H,false);
 vector<bool>w(W,false);

 for(int i=0;i<H;i++){
     for(int j=0;j<W;j++){
         if(a[i][j]=='#'){h[i]=true;w[j]=true;}
     }
 }
 for(int i=0;i<H;i++){
     for(int j=0;j<W;j++){
         if(h[i]&&w[j]){cout<<a[i][j];}
     }if(h[i])cout<<endl;
 }
 
 return 0;
}