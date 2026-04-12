#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<math.h>
#include<vector>
#include<cctype>
#include<string>
#include<set>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
std::string line;
typedef long long ll;

int main(){
   int   n,h[110];
   cin >> n;
   rep(i,n) cin >> h[i];

   int ans = 1;
   for(int i=1;i<n;i++){
      bool flg = 1;
      for(int j=0;j<i;j++){
            if(h[j] > h[i]) {
               flg = 0;
               break;
            }
      }
      if(flg) ans++;
   }

   cout << ans << endl;




   return 0;
}