#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
#define ll long long 
#define pb push_back
int main(){	
	fast;
		string s; cin>>s;
		ll ca=0,cb=0;
		for(ll i=0;i<3;i++){
			if(s[i]=='A') ca++;
			else cb++;
			}
		if(ca>0 && cb>0) cout<<"Yes";
		else cout<<"No";
		}
		
		
	
	

	
	
	
		