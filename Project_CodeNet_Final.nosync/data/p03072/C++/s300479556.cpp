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
    for(auto& val: arr)
        cin >> val;
    int ans = 0;
    int level = 0;
    for(auto& val : arr) {
        if (val >= level) {
            ans += 1;
            level = val;
        }
    }
    cout << ans << endl;
    return 0;
}


