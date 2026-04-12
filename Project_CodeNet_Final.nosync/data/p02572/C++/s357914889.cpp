#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
ll mod=1e9+7;

ll add(ll a,ll b){
    return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin>>n; ll sum=0; ll pre=0;
    for(int i=0;i<n;i++){
        ll x; cin>> x;
        sum=add(sum,mul(pre,x));
        pre+=x;

    }
    cout<<sum<<endl;


}
