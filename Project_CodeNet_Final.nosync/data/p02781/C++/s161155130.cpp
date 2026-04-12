//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pll pair<long long,long long>
//#define LONGLONG_MAX 10000000000000000
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans;
        
}
int fact[200005],fact_inv[200005];
void pre(){
	fact[0]=1;
	fact_inv[0]=1;
	for(int i=1;i<200005;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
		fact_inv[i]=power(fact[i],mod-2);
	}
}
long long ncr(long long n,long long r){
	if(n<r){return 0;}
	if(n==r||r==0){return 1;}
	return (((fact[n]*fact_inv[n-r])%mod)*fact_inv[r])%mod;
	//return x;	
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    int k;
    cin>>n>>k;
    pre();
    int x=n.size();
    
    int ans=0;
    ans+=ncr(x-1,k)*power(9,k);
    for(int i=1;i<n[0]-'0';i++)
    ans+=ncr(x-1,k-1)*power(9,k-1);
    int z=1;
    for(int i=1;i<x;i++){
        if(z==k){break;}
        if(n[i]!='0'){
            z++;
            //cout<<ans<<" ";
            ans+=ncr(x-i-1,k-z+1)*power(9,k-z+1);
            for(int j=1;j<n[i]-'0';j++)
            ans+=ncr(x-i-1,k-z)*power(9,k-z);
            //cout<<ans<<" ";
        }
    }
    if(z==k)ans++;
    cout<<ans;
    return 0;
}