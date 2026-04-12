#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define m 1000000007

int main(){
    ll sum=0, n=0, ans=0;
    int i=0, j=0;

    cin >> n;

    ll arr[n];

    for(i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i]%m;
        sum %= m;
    }

    for(i=0; i<n-1; i++){
        sum -= (arr[i]%m);
        if(sum<0) sum += m;
        ans += ((sum%m)*(arr[i]%m))%m;
        ans %= m;
    }

    cout << ans << endl;
    return 0;
}
