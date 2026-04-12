// Code by : h_mm 

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define t ll t; cin>>t; while(t--)
ll mod=1000000007;
using namespace std;

int main(void){
    int n;
    cin>>n;
    ll a[n], b[n];
    ll sum = 0;
    for(int i=0 ;i<n; i++){
    	cin>>a[i];
    	sum += a[i];
    	sum %= mod;
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
    	sum -= a[i];
    	if(sum<0) sum += mod;
    	ans += a[i]*(sum);
    	ans %= mod;
    }
    cout<<ans;
}