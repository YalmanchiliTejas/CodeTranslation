#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz size()
#define pb push_back 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
int main(){
	ll N,K;
	string s; cin>>N>>s>>K;
	rep(i,s.sz){
		if(s[K-1]!=s[i]) cout<<"*";
		else cout<<s[i];
	}   
}