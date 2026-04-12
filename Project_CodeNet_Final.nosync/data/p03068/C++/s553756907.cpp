#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
const ll MOD = 1e9 + 7; 
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  string s;
  cin>>s;
  int k;
  cin>>k;
  int i;
  for(i=0;i<s.length();i++){
  	if(i!=(k-1)&&s[i]!=s[k-1]){
  		s[i]='*';
	  }
  }
  cout<<s<<endl;
  
  return 0;
}