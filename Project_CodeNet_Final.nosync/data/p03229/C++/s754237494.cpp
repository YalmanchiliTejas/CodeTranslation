#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans1(n);
    vector<int> ans2(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int half = n / 2;
    int left, right;
    int count;

    ans1[0] = a[half];
    left = 0, right = n - 1;
    count = 1;
    while(true){
        ans1[count] = a[right];
        right--;
        count++;
        if(count == n) break;
        ans1[count] = a[left];
        left++;
        count++;
        if(count == n) break;
    }

    ans2[0] = a[half];
    left = 0, right = n - 1;
    count = 1;
    while(true){
        ans2[count] = a[left];
        left++;
        count++;
        if(count == n) break;
        ans2[count] = a[right];
        right--;
        count++;
        if(count == n) break;
    }

    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i < n - 1; i++) sum1 += abs(ans1[i + 1] - ans1[i]);
    for(int i = 0; i < n - 1; i++) sum2 += abs(ans2[i + 1] - ans2[i]);
    cout << max(sum1, sum2) << endl;

    return 0;
}
