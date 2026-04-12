#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define l long

using namespace std;

int main()
{
    int n; cin >> n;
    ll sum = 0,summ=0;
    ll ans = 0;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        summ+=a[i];
    }
    for(int i=0; i<n; i++){
            sum=((summ-a[i])%MOD)*a[i];
            sum%=MOD;
            ans+=sum;
            ans%=MOD;
            summ-=a[i];
        }

    cout << ans  << endl;
    return 0;
}
