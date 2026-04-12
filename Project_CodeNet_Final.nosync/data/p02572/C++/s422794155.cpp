#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1e9 +7;
void solve(){
    int n;
    
    ll sum=0;
    int a[1000000];
    cin>>n;
    for(int i=0; i< n; i++){
         cin>>a[i];
         sum +=a[i];
		sum %= mod;
            
    }
    ll ans= 0;
    for(int i = 0; i < n; i++){
			sum -= a[i];
			if (sum < 0) sum += mod;
			ans += a[i] * sum;
			ans %= mod;
		
		
		}
    

    cout<<ans<<"\n";

}
int main(){
    ios_base::sync_with_stdio(false); //macht programm I/O schneller
    cin.tie(NULL); //flush the io stream befor accepting your input
    solve();
}
