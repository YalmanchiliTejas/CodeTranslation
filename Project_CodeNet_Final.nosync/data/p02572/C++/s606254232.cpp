/******************************************
* AUTHOR : SOMU KUMAR *
* INSTITUTION : IIT BHUBANESWAR *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//code here...............//
int n;
cin>>n;
ll arr[n];
for(int i=0;i<n;i++){
	cin>>arr[i];
}
ll ans=0;
for(int i=n-2;i>=0;i--){
    ans=(ans%MOD+(arr[i]%MOD*arr[i+1]%MOD)%MOD)%MOD;
    arr[i]=(arr[i]+arr[i+1])%MOD;
}
cout<<ans%MOD<<endl;
return 0;
}