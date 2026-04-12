#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 int main() {
	int r,g,b;
   cin>>r>>g>>b;
   r*=100;
   g*=10;
   int sum =0;
   int check =0;
   sum = r+g+b;
   check = g+b;
   if(check%4==0){
   cout<<"YES";
   }else{
      cout<<"NO";
   }
	}