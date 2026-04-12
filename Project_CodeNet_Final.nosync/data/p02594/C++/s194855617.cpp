//By Zank100
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define din(t) long long t;cin>>t;
#define in(t) cin>>t;
#define full(t) t.begin(),t.end()
ll mul(ll a, ll b)
{
    return(((a%mod)*(b%mod))%mod);
}
ll modexp(ll b, ll e){
	ll res = 1;
	for(; e; b = b * b % mod, e >>= 1) if(e & 1) res = res * b % mod;
	return res;
}
ll modinv(ll a){
    ll x=mod-2;
	return modexp(a,x);
}
void Inp_Out(){
    #ifndef ONLINE_JUDGE
    freopen("alchemy_input.txt", "r", stdin);
    freopen("alchemy_output.txt", "w", stdout);
    #endif
}
//unsigned cntBits(unsigned ll number)return (ll)log2(number)+1;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	//Inp_Out();
	
    din(x);
    if(x>=30)cout<<"Yes\n";
    else cout<<"No\n";
	return 0;
}
