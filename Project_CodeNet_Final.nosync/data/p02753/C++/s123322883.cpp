#include<bits/stdc++.h>
using namespace std;
#define inf 100000000000000000
#define ll long long 
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define test ll t ; cin>>t; while(t--)
void mahakal(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
}
int main(){
	//mahakal(),fast;
	
	string str;
	cin>>str;
	ll flag1=0,falg2=0;
	for(ll i=0;i<str.length();i++){
		if(str[i]=='A')flag1=1;
		else falg2=1;
	} 
	if(falg2&flag1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}