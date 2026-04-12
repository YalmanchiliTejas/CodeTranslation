#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

ll sub(vector<int>& arr) {
    ll m = INT_MAX, ans = 0;
    int n = arr.size();
    for(int i = 1; i <= n; i++) {
        ans += llabs(arr[i%n] - arr[i-1]);
        m = min(m, llabs(arr[i%n] - arr[i-1]));
    }
    return ans-m;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> arr2(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int l = 0, r = n-1;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0)
            arr2[i] = arr[l++];
        else
            arr2[i] = arr[r--];
    }
    ll tmp = sub(arr2);
    l = 0, r = n-1;
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0)
            arr2[i] = arr[r--];
        else
            arr2[i] = arr[l++];
    }
    cout << max(tmp, sub(arr2)) << endl;

    return 0;
}


