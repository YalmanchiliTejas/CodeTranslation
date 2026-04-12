#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> cp(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        cp[i] = nums[i];
    }
    sort(nums.begin(), nums.end());
    int index = n / 2;
    for (int i = 0; i < n; i++) {
        if (cp[i] < nums[index]) {
            cout << nums[index];
        } else {
            cout << nums[index-1];
        }
        cout <<"\n";
    }
    return 0;
}
