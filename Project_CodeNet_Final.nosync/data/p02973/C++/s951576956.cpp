#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    reverse(arr.begin(), arr.end());
    vector<int> LIS = {};
    for(int i = 0; i < n; i++) {
        auto it = upper_bound(LIS.begin(), LIS.end(), arr[i]);
        if (it == LIS.end())
            LIS.push_back(arr[i]);
        else
            *it = arr[i];
    }
    cout << LIS.size() << endl;
    return 0;
}
