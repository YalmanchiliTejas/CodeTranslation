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
  int h[n];
  int i;
  for(i=0;i<n;i++){
  	cin>>h[i];
  }
  
  int w=h[0];
  int count=1;
  	for(int j=1;j<n;j++){
  		if(h[j]>=w){
  			w=h[j];
  			count++;
		  }
	  }
  
  
  cout<<count<<endl;
  
  return 0;
}