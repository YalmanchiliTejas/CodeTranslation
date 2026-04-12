/*
	
	@Raghul
*/
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
ll ans[100005];
ll fastpow(ll a,ll b){
	if(b==0)
		return 1LL;
	ll temp=fastpow(a,b/2);
	temp=temp*temp;
	if(b%2==1)
		temp=temp*a;
	return temp;
}	
int main(){ 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    if(n==3||n==5||n==7){
    	cout<<"YES";
    }
    else	cout<<"NO";
    return 0;
} 