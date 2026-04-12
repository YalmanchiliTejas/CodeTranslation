#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    int left = 0;
    int right = n - 1;
    int mid;
    if (n % 2 == 0) mid = (n - 1) / 2;
    else mid = n / 2;
    int num = mid;
    for(int i = 0; i < n - 1; i++)
    {
        if (left != mid) {
            ans += abs(a.at(num) - a.at(left));
            num = left;
            left++;
        }
        if (right != mid) {
            ans += abs(a.at(num) - a.at(right));
            num = right;
            right--;
        }
    }
    left = 0;
    right = n - 1;
    num = mid;
    long long ans2 = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if (right != mid) {
            ans2 += abs(a.at(num) - a.at(right));
            num = right;
            right--;
        }
        if (left != mid) {
            ans2 += abs(a.at(num) - a.at(left));
            num = left;
            left++;
        }
    }
    cout << max(ans, ans2) << endl; 
}