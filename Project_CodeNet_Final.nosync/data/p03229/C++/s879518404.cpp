#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int b[n];
    int mid;
    if (n % 2 == 1) {
        mid= (n + 1) / 2 - 1;
        b[0] = arr[mid];
        if (arr[mid] - arr[mid - 1] < arr[mid + 1] - arr[mid]) {
            for (int i = 0; i < mid; ++i) {
                b[(i + 1) * 2] = arr[i];
                b[i * 2 + 1] = arr[n - 1 - i];
            }
        } else {
            for (int i = 0; i < mid; ++i) {
                b[(i + 1) * 2] = arr[n - 1 - i];
                b[i * 2 + 1] = arr[i];
            }
        }
    } else {
        mid= n / 2;
        for (int i = 0; i < mid; ++i) {
            b[i * 2 + 1] = arr[i];
            b[i * 2] = arr[mid + i];
        }
    }
 
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (long long)abs(b[i - 1] - b[i]);
    }
 
    cout << ans ;
 
	return 0;
}