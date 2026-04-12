#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i = 0; i < n;i++)
#define ll long long

int main(){
  int n;cin>>n;
  vector<int>h(n);
  rep(i,n)
    cin>>h.at(i);
  int ans=1,hi=h.at(0);
  rep(i,n-1)
  {
    if(h.at(i+1)>=hi)
    {
      hi=h.at(i+1);
      ans++;
    }
  }
  cout<<ans;
}
    
    
    