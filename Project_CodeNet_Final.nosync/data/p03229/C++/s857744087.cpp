#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int GCD(int a, int b){return b == 0 ? a : GCD(b, a % b);}

vector<long long> arr;

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        long long j;
        cin >> j;
        arr.push_back(j);
    }

    sort(arr.begin(), arr.end());

    // Case 1 - Bigger numbers are inserted in between
    // Insert small numbers in between
    // Anywhere inside is okay, as long as it's not at the sides


    long long tot = 0, tot1 = 0, prev = 0;

    int left = 0, right = n - 1, parity = 0;

    while(left < right){
        if(parity % 2 == 0){
            if(parity > 0){
                tot += abs(arr[right] - prev);
            }
            prev = arr[right--];
        } else {
            tot += abs(arr[left] - prev);
            prev = arr[left++];
        }
        ++parity;
    }

    //cout << abs(arr[n - 1] - arr[right]) << " " << abs(arr[right] - prev) << endl;

    tot = max(tot + abs(arr[right] - prev), tot + abs(arr[n - 1] - arr[right]));

    prev = 0;
    left = 0;
    right = n - 1;
    parity = 1;

    while(left < right){
        if(parity % 2 == 0){
            tot1 += abs(arr[right] - prev);
            prev = arr[right--];
        } else {
            if(parity > 1)
                tot1 += abs(arr[left] - prev);
            prev = arr[left++];
        }
        ++parity;
    }

    tot1 = max(tot1 + abs(arr[right] - prev), tot1 + abs(arr[0] - arr[right]));

    cout << max(tot, tot1);

    return 0;
}
