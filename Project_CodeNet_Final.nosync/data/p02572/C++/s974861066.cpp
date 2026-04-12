#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define MOD 1000000007

int main(){
	#ifndef ONLINE_JUDGE
		freopen ("../input.txt", "r", stdin);
		freopen ("../output.txt", "w", stdout);
	#endif

    ll N; cin>>N;
    ll sum1=0, sum2=0;
    for(ll i=0 ; i<N ; i++){
        ll t; cin>>t;
        sum1 = (sum1+t)%MOD;
        sum2 = (sum2 + (t*t)%MOD)%MOD;
    }
    sum1 = (sum1*sum1)%MOD;
    ll ans = ((((sum1 - sum2)%MOD + MOD)%MOD)*500000004)%MOD;
    // cout<<sum1<<" "<<sum2<<endl;
    cout<<ans<<"\n";
    return 0;
}