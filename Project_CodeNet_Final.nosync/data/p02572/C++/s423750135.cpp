#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    long long arr[n] = {0};
    long long sum = 0;
    for(int x=0;x<n;x++){
        cin >> arr[x];
        sum = (sum + arr[x])%1000000007;
    }
    
    //cout << sum << endl;

    long long ans = 0;
    for(int x=0;x<n;x++){
        sum = sum - arr[x];

        if (sum < 0) sum += 1000000007;

        ans = (ans + arr[x]*sum)%1000000007;
    }

    cout << ans << '\n';
}