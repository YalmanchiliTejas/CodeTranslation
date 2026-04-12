#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>

using namespace std;
typedef long long ll;

//最小公倍数
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//最大公倍数
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

//for(int i = ; i < ; i++){}



int main(){
 int n;
 cin>>n;
 string s[n];
 int a[26];
 int tmp[26];
 for(int i =0; i < 26; i++){
   a[i]=0;
   tmp[i]=0;
 }
 for(int i = 0; i < n; i++){
   cin>>s[i];
   for(int j = 0;j < s[i].length(); j++){
     tmp[s[i][j]-'a']++;
   }
   for(int j =0; j < 26; j++){
     if(i==0){
       a[j]=tmp[j];
     }
     else{
       a[j]=min(a[j],tmp[j]);
     }
     tmp[j]=0;
 }
 }
 for(int i =0; i < 26; i++){
   for(int k = 0; k < a[i]; k++){
     cout<<(char)(i+'a');
   }
 }
 cout<<endl;
return 0;
}