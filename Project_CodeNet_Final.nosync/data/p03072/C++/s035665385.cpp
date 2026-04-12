#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
const ll mod=1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int res=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(i==0){res++;maxi=v[i];continue;}
        if(v[i]>=maxi)res++;
        maxi=max(maxi,v[i]);
    }
    cout<<res<<endl;
    return 0;
    }
