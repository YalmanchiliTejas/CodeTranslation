#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using vi = vector<int>;
using vll = vector<ll>;
ll fast_exp(ll base,ll e){
    ll r=1;
    while(e>0){
        if(e%2)r=(r*base);
        base=base*base;
        e/=2;
    }
    return r;
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,0));
    for(int i=n-1;i>=0;i--){
    	for(int j=i;j<n;j++){
    		if(i==j)dp[i][j]=v[i];

    		else dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
    	}
    }
    cout<<dp[0][n-1];

}