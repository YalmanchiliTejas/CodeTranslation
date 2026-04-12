#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<ctype.h>
#include<stdio.h>
#include<set>
#include<vector>
#include<map>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<numeric>
#include<string>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
if(a<b){return gcd(b,a);}
else if(a%b){return gcd(b,a%b);}
else{return b;}
}
int main(){
  ll x,y,z;
  cin>>x>>y>>z;
  ll k=0;
  while(x>=y*k+z*(k+1))k++;
  cout<<k-1<<endl;
}