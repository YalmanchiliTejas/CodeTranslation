#include<bits/stdc++.h>
#define int long long
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define mod 1000000007
#define garou99 ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main() {
 int n;
 cin>>n;
 vector<int> v(n,0);
 for(int i=0;i<n;i++)
 cin>>v[i];
 int ct=0,x=0;
 rep1(i,0,n){
x=(x%mod+v[i]%mod);
 }
 rep1(i,0,n){
	 ct=(ct%mod+((x%mod-v[i]+mod)%mod)*(v[i]%mod));
	 x=(x%mod-v[i]%mod+mod)%mod;
 }
 cout<<ct;
	}