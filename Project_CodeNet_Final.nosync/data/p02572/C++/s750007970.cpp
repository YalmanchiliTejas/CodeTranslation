#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mk make_pair
#define mod 1000000007
//#define mo 998244353
string str;
//map<int, int>::iterator itr; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    ll arr[n],sum[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sum[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        sum[i]=arr[i]+sum[i+1];
    }
    ll ans=0;
    for(int i=0;i<n-1;i++){
        sum[i+1]=sum[i+1]%mod;
        ll p=sum[i+1]*arr[i];
        p=p%mod;
        ans+=p;
        ans=ans%mod;
    }cout<<ans;
    return 0;
}
