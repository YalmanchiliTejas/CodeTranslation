#include <bits/stdc++.h>

using namespace std;

int nums[100000 + 5];
int LNDSL(int sequence[], int n){
    if (n == 0)
        return 0;
    vector<int> tails;
    tails.push_back(sequence[0]);
    for (size_t i = 1; i < n; i++){
        if (sequence[i] <= tails.back())
            tails.push_back(sequence[i]);
        else {
            *upper_bound(tails.begin(), tails.end(), sequence[i], greater<int>()) = sequence[i];
        }
    }
    return tails.size();
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    printf("%d", LNDSL(nums, n));
}