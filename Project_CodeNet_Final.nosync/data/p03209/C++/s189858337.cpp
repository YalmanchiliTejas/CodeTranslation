#include<bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include<iostream>
#include <string>
using namespace std;
typedef long long ll;
#define pb pushback
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,j,n) for(int i=j;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)

ll a[51];
ll p[51];

ll num(ll n, ll x){
  ll ans;
  if(x<=1){
    if(n==0&&x==1)ans=1;
    else ans=0;
  }
  else if(x<=a[n-1]+1)ans=num(n-1,x-1);
  else ans=p[n-1]+num(n-1,x-a[n-1]-2)+1;
  return ans;
}

int main() {
    int n;
    ll x;
	cin >> n>>x;
    
    a[0]=1;
    p[0]=1;
    fr(i,50){
      a[i+1]=a[i]*2+3;
      p[i+1]=p[i]*2+1;
    }
    
      cout << num(n,x) << endl;
}