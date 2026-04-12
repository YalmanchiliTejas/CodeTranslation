#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    long long int ans = 0;
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }
    long long int sum[n] = {0};
    sum[0] = arr[0] % 1000000007;
    for (int i = 1; i < n;i++) {
        sum[i] = (arr[i] % 1000000007 + sum[i - 1] % 1000000007) % 1000000007;
        sum[i] = sum[i] % 1000000007;
    }
    /*for (int i = 0; i < n;i++) {
        cout << sum[i] << " ";
    }*/
    //cout << endl;
    for (int i = 0; i < n;i++) {
        //cout << i << " " << arr[i] << " " << sum[n - 1] - sum[i] ;
        long long int temp = sum[n - 1] - sum[i];
        if (temp < 0)   temp += 1000000007;
        
        ans = (ans % 1000000007 + (arr[i] % 1000000007 * (temp) % 1000000007 ) % 1000000007) % 1000000007;
        ans = ans % 1000000007;
        //cout << " " << ans << endl;
    }
    cout << ans % 1000000007 << endl;
	return 0;
}
