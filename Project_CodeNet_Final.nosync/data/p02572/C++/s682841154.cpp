    #include<bits/stdc++.h>
    using namespace std;
     
    #define ll long long
    #define mod 1000000007
    #define IO_fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     
    int main(){
        IO_fast
        int n;
        cin >> n;
        ll a[n];
        for(int i = 0 ; i<n ; i++) cin >> a[i];
     
        ll sum[n];
        sum[0] = a[0]%mod;
        for(int i = 1 ; i<n ; i++){
            sum[i] = a[i]%mod + sum[i-1];
            sum[i] = sum[i]%mod;
        }

        ll answer = 0;
        for(int i = 0 ; i<n ; i++){
            answer = (answer+(a[i]%mod)*(sum[n-1]-sum[i]+mod))%mod;
            answer = answer%mod;
        }
     
        cout << answer << endl;
        return 0;
    }