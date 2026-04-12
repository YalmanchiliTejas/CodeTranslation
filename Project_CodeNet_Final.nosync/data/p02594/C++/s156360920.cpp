#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
#define mod 1000000007
#define pll pair<long long,long long>
using namespace std;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans;
        
}
bool prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    if(n<30)cout<<"No";
    else cout<<"Yes";
    return 0;
}