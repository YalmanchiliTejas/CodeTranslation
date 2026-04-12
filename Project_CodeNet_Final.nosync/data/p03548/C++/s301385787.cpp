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
   int x,y,z;
   cin >> x >> y >> z;

   int ans = 0;
   int cnt = 0;
   while(ans <= x){
      cnt++;
      if(cnt>=2) ans += y + z;
      else ans += cnt*y + 2*z;
   }
   cout << cnt-1  << endl;



   return 0;
}