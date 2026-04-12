#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define frn(i,n) for(int i=n-1;i>=0;i--)
#define fr1(i,n) for(ll i=1;i<=n;i++)
#define frn1(i,n) for(int i=n;i>0;i--)
#define N 100002
#define ll long long
#define mid(a,b) a+(b-a)/2


void solve(){
    int n;
    cin>>n;
    unsigned long long sum=0;
    unsigned long long arr[200005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //sum+=arr[i];
    }
    unsigned long long ans=0;
    for(int i=n-2;i>=0;i--){
        sum+=arr[i+1];
      	ans = (ans%mod + ((arr[i]%mod)*(sum%mod))%mod)%mod;
    }
    cout<<ans<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}