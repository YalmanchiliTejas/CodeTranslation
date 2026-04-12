#define _GLIBCXX_DEBUG
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
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
const ll inf = 1000000007;
int main() {
  ll n; cin >>n;
  vector<string> s(n);
  map<char,ll> mpans;
  rep(i,n) cin>>s[i];
  rep(i,s[0].size())mpans[s[0][i]]++;
  rep2(i,1,n){
    map<char,ll> mp;
    rep(j,s[i].size())mp[s[i][j]]++;
    for( char a='a';a<='z';a++)mpans[a]=min(mpans[a],mp[a]);
  }
  string ans ="";
  for( char a='a';a<='z';a++)if(mpans[a]>0)rep(i,mpans[a])ans+=a;
  cout <<ans<<endl; 
}