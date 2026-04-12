//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 998244353
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pll pair<long long,long long>
#define LONGLONG_MAX 100000000000000
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans;
        
}
double search(double start,double end,double n){
    if(end-start<1e-9)return start;
    double mid=(start+end)/2;
    if(mid*mid>n)return search(start,mid,n);
    else return search(mid,end,n);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans[s+1]={0};
    ans[0]=1;
    int ans1=0;
    for(int i=0;i<n;i++){
        for(int j=s;j>0;j--){
            if(a[i]+j>s)continue;
            ans[a[i]+j]+=ans[j];
            ans[a[i]+j]%=mod;
        }
        if(a[i]<=s){ans[a[i]]+=i+1;ans[a[i]]%=mod;}
        ans1+=ans[s];
        ans1%=mod;
    }
    cout<<ans1;
    //cout<<ans[s];
    return 0;
}
