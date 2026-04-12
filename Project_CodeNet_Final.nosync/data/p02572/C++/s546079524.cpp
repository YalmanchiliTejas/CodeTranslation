#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
#define mod 1000000007
#define pll pair<long long,long long>
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
//find_by_order() ->  iterator to the k-th largest element (counting from zero)
//order_of_key() ->    the number  items in a set that are strictly smaller than our item aka index in set
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    //(a*b)%m=((a%m)*(b%m))%m
    int x=0;
    for(int i=0;i<n;i++){
        x+=a[i];
        x%=mod;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        x-=a[i];
        if(x<0)x+=mod;
        ans+=(a[i]*x);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}