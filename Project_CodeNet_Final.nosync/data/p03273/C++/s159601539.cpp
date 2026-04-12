#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define _GLIBCXX_DEBUG
#define V vector<ll>
using namespace std;
using ll = long long;

int main(){
   int h,w;
   cin>>h>>w;
   vector<string> a(h);
   rep(i,0,h) cin>>a[i];

   vector<int> x(w),y(h);
   rep(i,0,w) x[i]=false;
   rep(i,0,h) y[i]=false;

   rep(i,0,h){
      rep(j,0,w){
         if(a[i][j]=='#'){
            y[i]=true;
            x[j]=true;
         }
      }
   }

   rep(i,0,h){
      if(y[i]==true){
         rep(j,0,w){
            if(x[j]==true){
               cout<<a[i][j];
            }
         }
         cout<<endl;
      }
   }
}
