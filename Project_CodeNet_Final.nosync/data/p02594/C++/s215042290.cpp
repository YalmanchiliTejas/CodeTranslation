#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll gcd(ll a, ll b);
int main(){
cin.tie(0);
int x;
  cin>>x;
  if(x>=30)cout <<"Yes";
  else cout<<"No";

return 0;
}






ll gcd(ll a, ll b){

   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }

}
