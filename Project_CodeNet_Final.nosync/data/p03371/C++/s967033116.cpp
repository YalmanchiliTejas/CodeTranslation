#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long 
using namespace std;
int main(){
  ll a,b,c,x,y;
  cin >>a>>b>>c>>x>>y;
  ll ans=1000000009;
  ll i=0;
  ll d=0;
  ll e=0;
while(i/2<=max(x,y)){
  d=0;
  e=0;
    if(x>i/2){
       d=x-i/2;
    }
    if(y>i/2){
        e=y-i/2;
    }
      ans=min(ans,i*c+d*a+e*b);
  i++;
}
  cout <<ans<<endl;
}
      
  