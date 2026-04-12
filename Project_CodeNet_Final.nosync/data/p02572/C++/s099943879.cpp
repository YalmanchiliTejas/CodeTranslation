#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin>>n;
    ll a[n];
    for (int i = 0; i<n; i++)
        cin>>a[i];
    
    ll sum = 0;
    ll ans = 0;

    for ( int i =0; i<n; i++ )
        sum = (sum+a[i])%1000000007;

    for ( int i=0; i<n-1; i++ )
        {
            sum -=a[i];
            if ( sum<0 )
                sum += 1000000007;
            ans = ( ans + a[i]*sum)%1000000007;
        }

    cout<<ans;
}