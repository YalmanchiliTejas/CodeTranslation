#include<bits/stdc++.h>
using namespace std;
int arr[100010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    multiset<int> ms;
    int answer = 1;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            if (ms.lower_bound(arr[i]) == ms.begin()) {
                ++answer;
            } else {
                ms.erase(--ms.lower_bound(arr[i]));
            }
        }
        ms.insert(arr[i]);
    }
    cout << answer;
}