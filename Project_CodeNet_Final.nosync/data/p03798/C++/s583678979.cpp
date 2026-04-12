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
int main(){
  ll n; cin >>n;
  string s; cin >>s;
  string ans="S";
  rep(i,n){
    if(i==0){
      ans+="S";
      continue;
    }
    if(s[i]=='o'){
      if(ans[i]=='S'){
        ans+=ans[i-1];
      }else{
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }
    }else{
      if(ans[i]=='S'){
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }else{
        ans+=ans[i-1];
      }
    }
  }
  if(s[0]=='o'){
    if(ans[0]==ans[n]){
      if(ans[1]==ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }else{
    if(ans[0]==ans[n]){
      if(ans[1]!=ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }

  
  
  
ans="S";
  rep(i,n){
    if(i==0){
      ans+="W";
      continue;
    }
    if(s[i]=='o'){
      if(ans[i]=='S'){
        ans+=ans[i-1];
      }else{
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }
    }else{
      if(ans[i]=='S'){
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }else{
        ans+=ans[i-1];
      }
    }
  }
  if(s[0]=='o'){
    if(ans[0]==ans[n]){
      if(ans[1]==ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }else{
    if(ans[0]==ans[n]){
      if(ans[1]!=ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  ans="W";
  rep(i,n){
    if(i==0){
      ans+="S";
      continue;
    }
    if(s[i]=='o'){
      if(ans[i]=='S'){
        ans+=ans[i-1];
      }else{
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }
    }else{
      if(ans[i]=='S'){
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }else{
        ans+=ans[i-1];
      }
    }
  }
  if(s[0]=='o'){
    if(ans[0]==ans[n]){
      if(ans[1]!=ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }else{
    if(ans[0]==ans[n]){
      if(ans[1]==ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }

  
  
  
ans="W";
  rep(i,n){
    if(i==0){
      ans+="W";
      continue;
    }
    if(s[i]=='o'){
      if(ans[i]=='S'){
        ans+=ans[i-1];
      }else{
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }
    }else{
      if(ans[i]=='S'){
        if(ans[i-1]=='S')ans+="W";
        else ans+="S";
      }else{
        ans+=ans[i-1];
      }
    }
  }
  if(s[0]=='o'){
    if(ans[0]==ans[n]){
      if(ans[1]!=ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }else{
    if(ans[0]==ans[n]){
      if(ans[1]==ans[n-1]){
        ans.erase(n);
        cout <<ans<<endl;
        return 0;
      }
    }
  }
  
  
  cout <<-1<<endl;
}