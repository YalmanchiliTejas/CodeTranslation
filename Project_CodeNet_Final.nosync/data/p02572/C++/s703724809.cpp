#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const long long modi = 1000000007;

int main() {
    int n;
    int kinda = 0;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i != 0){
            kinda+=arr[i];
            kinda = kinda % modi;
        }
    }

    long long ans = 0;
    // for (int i = 0; i < n - 1; i++){
    //    for (int j = i + 1; j < n; j++){
    //        ans += arr[i] * arr[j];
    //        ans = ans % modi;
    //    }
    //}
    //cout << ans;
    for (int i = 0; i < n; i++){
        ans += arr[i] * kinda;
        ans = ans % modi;
        kinda -= arr[i + 1];
        if (kinda < 0){
            kinda+=modi;
        }
        kinda = kinda % modi;
    }
    cout << ans;
}
